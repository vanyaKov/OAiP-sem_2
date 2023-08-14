#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int countChet = 0;
    Tree* mainRoot = new Tree;
    int choice;

    // 13 8 17 4 11 15 25 2 6 22 27 20 33
    while (1)
    {
        int numLeft = 1;
        cout << "\n";
        cout << "1 - Добавить элемент;\n";
        cout << "2 - Вывести дерево;\n";
        cout << "3 - Удалить элемент;\n";
        cout << "4 - Прямой обход с выводом;\n";
        cout << "5 - Обратный обход с выводом;\n";
        cout << "6 - Cмешанный обход с выводом;\n";
        cout << "7 - Балансировка дерева;\n";
        cout << "8 - Задание из 11 лаб 8 вар;\n";
        cout << "0 - Выход\n";
        cout << "Выберите:\n";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
        {
            cout << "\nДля остановки введите отрицательное число." << endl;
            cout << "Введите элемент: ";
            cin >> choice;
            while (choice > 0)
            {
                mainRoot->AddNode(choice);
                cout << "Введите элемент: ";
                cin >> choice;
                if (choice % 2 == 0)
                {
                    countChet++;
                }
            }
            break;
        }

        case 2:
        {
            if (!mainRoot->node)
                cout << "В дереве ничего нет.\n";
            else
                mainRoot->PrintTree(mainRoot->node, 0);
            break;
        }

        case 3:
        {
            int key;
            cout << "Введите ключ элемента, который хотите удалить: ";
            cin >> key;
            mainRoot->Delete(key);
            break;
        }

        case 4:
        {
            if (!mainRoot->node)
                cout << "В дереве ничего нет.\n";
            else
                mainRoot->DirectBypass(mainRoot->node);
            break;
        }

        case 5:
        {
            if (!mainRoot->node)
                cout << "В дереве ничего нет.\n";
            else
                mainRoot->DownScan(mainRoot->node);
            break;
        }

        case 6:
        {
            if (!mainRoot->node)
                cout << "В дереве ничего нет.\n";
            else
                mainRoot->ReverseBypass(mainRoot->node);
            break;
        }

        case 7:
        {
            mainRoot->counter = 0;
            if (!mainRoot->node)
                cout << "В дереве ничего нет.\n";
            else if (mainRoot->Balance(mainRoot->node))
                cout << "Дерево сбалансировано." << endl;
            else
                cout << "Дерево не сбалансировано." << endl;
            break;
        }

        case 8:
            {
                Node* maxNode = nullptr;
                int maxSum = INT_MIN;
                mainRoot->FindMaxSumNode(mainRoot->node, maxNode, maxSum);
                
                if (maxNode)
                    {
                        cout << "Удаляемая вершина с максимальной суммой: " << maxNode->key << endl;
                        mainRoot->Delete(maxNode->key);
                    }
                else
                    {
                        cout << "Дерево пустое или не содержит вершин." << endl;
                    }
                break;
            }
            
        case 0:
            // Выход из программы
            return 0;
            
            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }
    
    return 0;
}

