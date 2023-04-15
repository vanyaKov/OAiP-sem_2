#pragma once
struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2);
void show_stacks(Stack* myStk1, Stack* myStk2);
void toFile(Stack* myStk);
int fromFile(Stack* myStk);
