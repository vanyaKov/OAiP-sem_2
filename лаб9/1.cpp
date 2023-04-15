#include <iostream>
//oneByOne (Object &To, Object &from1, Object &from2) - функцию, которая формирует список To, включив в него поочередно элементы из списков from1 и from2.  
using namespace std;

struct Node{
	double data;
	Node *prev, *pnext;
public:
	Node(double data){
		this->data = data;
		this->prev = this->pnext = NULL;
	}
};

struct LinkedL{
public:
	Node *head, *tail;
	
public:
	LinkedL(){
		head = tail = NULL;
	}
	Node *push(double data){
		Node *ptr = new Node(data);
		ptr->pnext = head;
		if (head != NULL) {
			head->prev = ptr;
		}
		if (tail == NULL) {
			tail = ptr;
		}
		head = ptr;
		return ptr;
	}
};

struct Node2{
	double data2;
	Node2 *prev2, *pnext2;
public:
	Node2(double data2){
		this->data2 = data2;
		this->prev2 = this->pnext2 = NULL;
	}
};

struct Node3{
	double data3;
	Node3 *prev3, *pnext3;
public:
	Node3(double data3){
		this->data3 = data3;
		this->prev3 = this->pnext3 = NULL;
	}
};

struct LinkedL2{
public:
	Node2 *head2, *tail2;
	
public:
	LinkedL2(){
		head2 = tail2 = NULL;
	}
	Node2 *push(double data2){
		Node2 *ptr2 = new Node2(data2);
		ptr2->pnext2 = head2;
		if (head2 != NULL) {
			head2->prev2 = ptr2;
		}
		if (tail2 == NULL) {
			tail2 = ptr2;
		}
		head2 = ptr2;
		return ptr2;
	}
};

struct LinkedL3{
public:
	Node3 *head3, *tail3;
	
public:
	LinkedL3(){
		head3 = tail3 = NULL;
	}
	Node3 *push(double data3){
		Node3 *ptr3 = new Node3(data3);
		ptr3->pnext3 = head3;
		if (head3 != NULL) {
			head3->prev3= ptr3;
		}
		if (tail3 == NULL) {
			tail3 = ptr3;
		}
		head3 = ptr3;
		return ptr3;
	}
};


int main(int argc, char *argv[]) {
	int choice;
	LinkedL lst;
	LinkedL2 lst2;
	LinkedL3 lst3;
	int ar1[100], ar2[100], s = 0, i = 0, j = 0;
	cin >> choice;
	while (choice != 5) {
		switch (choice) {
			case 1:
				cout << "Введитие число в первый список";
				cout << endl;
				double n,n2;
				cin >> n;
				cout << endl;
				lst.push(n);
				
				cout << "Введитие число во второй список";
				cout << endl;
				cin >> n2;
				cout << endl;
				lst2.push(n2);
				s++;
				
				break;
			case 2:
				cout << "Первый список:";
				for (Node*ptr = lst.head; ptr!=NULL; ptr = ptr->pnext) {
					cout << "-> " << ptr->data << " -> ";
				}
				cout << "NULL";
				cout << endl;
				
				cout << "Второй список:";
				for (Node2*ptr2 = lst2.head2; ptr2!=NULL; ptr2 = ptr2->pnext2) {
					cout << "-> " << ptr2->data2 << " -> ";
				}
				cout << "NULL";
				cout << endl;
				
				cout << "Третий список:";
				for (Node3*ptr3 = lst3.head3; ptr3!=NULL; ptr3 = ptr3->pnext3) {
					cout << "-> " << ptr3->data3 << " -> ";
				}
				cout << "NULL";
				break;
			case 3:
				for (Node*ptr = lst.tail;ptr!=NULL; ptr = ptr->prev) {
					ar1[i] = ptr->data;
					i++;
				}
				for (Node2*ptr2 = lst2.tail2;ptr2!=NULL; ptr2 = ptr2->prev2) {
					ar2[j] = ptr2->data2;
					j++;
				}
				
				for (int t = 0; t < s; t++) {
					lst3.push(ar2[t]);
					lst3.push(ar1[t]);
				}
		}
		cin >> choice;
	}
	
}