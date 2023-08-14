#include "Hash.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
struct AAA
{
  int key;
  string keyString;
  const char* mas;
  AAA(int k, const char z[])
  {
    key = k;  mas = z;
  } AAA() {}
  
};
//-------------------------------
int key(void* d)
{
  AAA* f = (AAA*)d;
  return f->key;
}

//-------------------------------
void AAA_print(void* d)
{
  cout << " ключ " << ((AAA*)d)->keyString << " - " << ((AAA*)d)->mas << endl;
}

//-------------------------------
int getkeyInt(string k)
{
  //переменная нового ключа
  int key = 0;
  for (int i = 0; i < k.size(); i++){
      key += (int)k[i];
    }
  
  return key;
}

//-------------------------------
 
int main(int argc, char* argv[]){
    int siz = 10, choice;
    string k;
    cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
    Object H = create(siz, key);
    for (;;)
      {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;
        switch (choice)
        {
          case 0:  exit(0);
          case 1: H.scan(AAA_print);  break;
          case 2: {
						AAA* a = new AAA;
            char* str = new char[20];
            cout << "введите ключ" << endl;
            getchar();
            getline(cin, k);

            int key = 0;
            
            a->key = getkeyInt(k);
            a->keyString = k;
            
            cout << "введите строку" << endl;
            cin.getline(str, 20);
            a->mas = str;
            if (H.N == H.size)
              cout << "Таблица заполнена" << endl;
            else
              H.insert(a);
          } break;
          case 3: {  cout << "введите ключ для удаления" << endl;
            getchar();
            getline(cin, k);
            H.deleteByKey(getkeyInt(k));
          }  break;
          case 4: {  cout << "введите ключ для поиска" << endl;
            getchar();
            getline(cin, k);

            if (H.search(getkeyInt(k)) == NULL)
              cout << "Элемент не найден" << endl;
            else
              AAA_print(H.search(getkeyInt(k)));
          }  break;
        }
      }
  return 0;
}