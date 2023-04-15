#include <iostream>
using namespace std;
struct Stack
{
	int data;             //информационный элемент
	Stack *head;		 //вершина стека 
	Stack *next;
};

struct Stack1
{
	int data1;             //информационный элемент
	Stack *head1;		 //вершина стека 
	Stack *next1;
};

struct Stack2
{
	int data2;             //информационный элемент
	Stack *head2;		 //вершина стека 
	Stack *next2;
};
	
void push(int x, Stack *myStk,  Stack1 *myStk1,  Stack2 *myStk2){	
	Stack* e = new Stack;	//выделение памяти для нового элемента
	Stack1* f = new Stack1;
	Stack2* p = new Stack2;
	e->data = x;  //запись элемента x в поле v 
	if (e->data > 50) {
		f->data1 = e->data;
		f->next1 = myStk1->head1;
	}
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

int pop(Stack *myStk){
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else{
		Stack *e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}

void show(Stack *myStk, Stack1 *myStk1){
	Stack* e = myStk->head;	//объявляется указатель на вершину стека
	Stack1*f = myStk1->head1;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL){	
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void clear(Stack **myStk){
	Stack *p, *p1;
	p = *myStk;
	while (p!= NULL){
		p1 = p->next;
		delete p;
		p=p1;
	}
}

int main()
{	int choice;
	Stack *myStk = new Stack;
	Stack1 *myStk1 = new Stack1;
	Stack2 *myStk2 = new Stack2;//выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	for (;;)
		{	cout << "Выберите команду:" << endl;
			cout << "1 - Добавление элемента в стек" << endl;
			cout << "2 - Извлечение элемента из стека" << endl;
			cout << "3 - Вывод стека" << endl;
			cout << "4 - Выход" << endl;
			cin >> choice;
			switch (choice)
			{
				case 1: cout << "Введите элемент: " << endl;
				cin >> choice;
				push(choice, myStk, myStk1, myStk2);
				break;
				case 2: choice = pop(myStk);
					if (choice != -1)
						cout << "Извлеченный элемент: " << choice << endl; 
					break;
				case 3: cout << "Весь стек: " << endl;
					show(myStk);
					show(myStk1);
					break;
				case 4:
					clear(&myStk);
					break;
				case 5: return 0; 
				break;
			}
		}
	return 0;
}

