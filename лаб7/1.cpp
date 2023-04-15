#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include "myStack.h"
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;
void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
int pop(Stack* myStk)
{
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		return a;
}
void show(Stack* myStk)
{
	Stack* e = myStk->head;
	bool work = false;
	int a;
	while (e != NULL)
	{
		a = e->data;
		cout << a << "-->";
		e = e->next;
		work = true;
	}
}
void clear(Stack* myStk)
{	
	while (myStk->head != NULL) {
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		}
}
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2)
{
	while (myStk1->head != NULL) {
		Stack* e1 = myStk1->head;
		int a = myStk1->head->data;
		myStk1->head = myStk1->head->next;
		delete e1;
	}
	while (myStk2->head != NULL) {
		Stack* e2 = myStk2->head;
		int a = myStk2->head->data;
		myStk2->head = myStk2->head->next;
		delete e2;
	}
	
	Stack* e = myStk->head;
	bool work = false;
	int a;
	while (e != NULL)
	{
		a = e->data;
		if (a > 50) {

			Stack* e1 = new Stack;
			e1->data = a;
			e1->next = myStk1->head;
			myStk1->head = e1;
		}
		if (a <= 50) {

			Stack* e2 = new Stack;
			e2->data = a;
			e2->next = myStk2->head;
			myStk2->head = e2;
		}
			e = e->next;
	}
}
void show_stacks(Stack* myStk1, Stack* myStk2) {
	Stack* e1 = myStk1->head;
	bool work = false;
	int a;
	while (e1 != NULL)
	{
		a = e1->data; 
		cout << a << "-->";
		e1 = e1->next;
		work = true;
	}
	Stack* e2 = myStk2->head;    
	work = false;
	while (e2 != NULL)
	{
		a = e2->data;       
		cout << a << "-->";
		e2 = e2->next;
		work = true;
	}
}

void toFile(Stack* myStk)
{
	Stack* e = myStk->head;
	fout.open("file.txt");
	if (fout.fail())
	{
		exit(1);
	}
	while (e != NULL)
	{
		fout << e->data << " ";
		e = e->next;
	}
	fout.close();
}
int fromFile(Stack* myStk)
{
	fin.open("file.txt");
	int value;
	fin >> value;
	if (fin.eof()) {
		fin.close();
		return -1;
	}
	Stack* Stkfile = new Stack;
	Stkfile->data = value;
	myStk->head = Stkfile;
	while (true) {
		fin >> value;
		if (fin.eof()) {
			break;
		}
		Stkfile->next = new Stack;
		Stkfile = Stkfile->next;
		Stkfile->data = value;
	}
	Stkfile->next = NULL;
	fin.close();
	return 1;
}

