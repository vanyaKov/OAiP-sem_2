#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
struct list
{	int info;
	list* next;
	char symbol;
};

void menu(void)
{   cout<<"Сделайте выбор:"<<endl;
	cout<<" 1 - Ввод числа"<<endl;
	cout<<" 2 - Удаление числа"<<endl;
	cout<<" 3 - Вычисление суммы отрицательные и крартные 2"<<endl;
	cout<<" 4 - Запись в файл"<<endl;
	cout<<" 5 - Чтение из файла"<<endl;
	cout<<" 6 - Поиск"<<endl;
	cout<<" 7- Выход"<<endl;
}

void insert(list *&p, int value)
{  list *newP = new list;
	if (newP!= NULL)
	{    newP->info = value;
		newP->next = p;
		p = newP;
	}
	else
		cout<<"Операция добавления не выполнена"<<endl;
}

void search(list* p) {
	bool isFnd = false;
	float element;
	int counter = 0;
	cout << "Enter the element: ";
	cin >> element;
	list* fnd = p;
	while (fnd) {
		if (fnd->info == element) {
			isFnd = true;
			cout << "Element is founded, its sequential number is " << counter + 1 << endl;
			break;
		}
		fnd = fnd->next;
		counter++;
	}
	if (!isFnd)
		cout << "Element isn't founded" << endl;
}

void printList(list *p)
{    if (p == NULL)
	cout<<"Список пуст"<<endl;
	else
		{   cout<<"Список:"<<endl;
			while (p!= NULL)
				{   cout<<"-->"<<p->info;
					p = p->next;
				}
			cout<<"-->NULL"<<endl;
		}
}

float del(list*& p, float value) {
	list* previous, * current, * temp;
	if (value == p->info) {
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->info != value) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}


void sum(list *p)
{    float sm = 0;
	if (p == NULL)
		cout<<"Список пуст"<<endl;
	else
		{    while (p!= NULL)
			{    if(p->info < 0 && p->info % 2 == 0)
				sm = sm + (p->info);
				p = p->next;
			}
			cout<<"Сумма = "<<sm<<endl;
		}
}

int IsEmpty(list *p)
{    return p == NULL;}

void writeToFile(list*& p) {
	list *temp = p;
	ofstream file1("myList2.txt");
	if (file1.fail()) {
		cout << "Error opening the file";
		exit(1);
	}
	while (temp) {
		float nn = temp->info;
		file1 << nn << endl;
		temp = temp->next;
	}
	file1.close();
	cout << "Information is written into the file" << endl;
}

void readFromFile(list*& p) {
	char buf[10];
	
	ifstream file1("myList2.txt");
	if (file1.fail()) {
		cout << "Error opening the file";
		exit(1);
	}
	while (!file1.eof()) {
		file1.getline(buf, 10);
		if (strlen(buf))
			insert(p, atof(buf));
		cout << "-->" << buf;
	}
	cout << "-->NULL" << endl;
	file1.close();
}


void clean(list**h){
	list *p, *p1;
	p = *h;
	while (p!= NULL) {
		p1 = p->next;
		delete p;
		p=p1;
	}
	*h = NULL;
	
}

int main()
{   setlocale(LC_CTYPE, "Russian");	list *first = NULL;	int choice;
	float value;
	menu();
	cout<<" ? ";
	cin>>choice; 
	while (choice != 7) 
		{   switch (choice) 
			{ 	case 1: cout<<"Введите число ";
				cin>>value;
				insert(first, value);
				printList(first);
				break;
			case 2:   if (!IsEmpty(first))
				{ 	cout<<"Введите удаляемое число ";
					cin>>value;
					if (del(first, value))
					{ 	cout<<"Удалено число " << value<<endl; 
						printList(first);
					}
					else
						cout<<"Число не найдено"<<endl; 
				}
				else
					cout<<"Список пуст"<<endl;
				break;
			case 3:   sum(first);
				break;
				default:  cout<<"Неправильный выбор"<<endl;
					menu();
					break;
			case 4:
				writeToFile(first);
				break;
			case 5:
				clean(&first);
				readFromFile(first);
				break;
			case 6:
				search(first);
				break;
				
		}
		cout<<"?  ";
		cin>>choice;
	}
	cout<<"Конец"<<endl;
	return 0; 
}


