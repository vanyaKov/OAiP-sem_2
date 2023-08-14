#include <iostream>
#include "Tree.h"
#include <fstream>
using namespace std;
struct NodeTree
{
	int key;
	int fNum;
	int sNum;
	NodeTree* left;
	NodeTree* right;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key < ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT;
	return rc;
}
//-------------------------------
void printNode(void* x)               // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << " " << ends;
}

//-------------------------------
bool buildTree(const char* FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE* inFile = fopen(FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // заполнение дерева 
	{
		int num;
		fscanf(inFile, "%d", &num);
		NodeTree* a = new NodeTree();
		a->key = num;
		tree.insert(a, 8, 1);
	}
	fclose(inFile);
	return rc;
}

FILE* outFile;
//-------------------------------
void saveToFile(void* x)              // Запись одного элемента в файл
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}
//-------------------------------
void saveTree(btree::Object& tree, const char* FileName)    //Сохранение дерева в файл 
{
	fopen(FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);
}
//-------------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	void* elementKey = 0;
	int MAX = 0;

	btree::Object demoTree = btree::create(cmpfnc);
	int k, choice;
	for (;;)
	{
		NodeTree* a = new NodeTree;
		cout << "1 - вывод дерева на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - сохранить в файл" << endl;
		cout << "5 - загрузить из файла" << endl;
		cout << "6 - очистить дерево" << endl;
		cout << "7 - удаление элемента с макс суммой" << endl;
		cout << "8 - нисходящий обход" << endl;
		cout << "9 - смешанные обход" << endl;
		cout << "10 - проверка на сбалансированность дерева" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:{
			demoTree.Root->scanByLevel(printNode);
			break;
		}
		case 2: 	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			cout << "Введите первое число: "; cin >> a->fNum;
			cout << "Введите второе число: "; cin >> a->sNum;
			demoTree.insert(a, a->fNum, a->sNum);
			break;
		case 3:  	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, "G.txt");
			break;
		case 5:  	buildTree("G.txt", demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		case 7:
			findMaxElement(demoTree.getRoot(), &MAX, &elementKey);
			demoTree.deleteByData(elementKey);
			break;
		case 8:
			postOrderTravers(demoTree.getRoot());
			cout << endl;
			break;
		case 9:
			inOrderTravers(demoTree.getRoot());
			cout << endl;
			break;
		case 10: {
				if (isHeightBalanced(demoTree.getRoot()))
				{
					cout << "Дерево сбалансированно" << endl;
				}
				else {
					cout << "Дерево не сбалансированно" << endl;
				}
				break;
			}
		}
	}
	return 0;
}
