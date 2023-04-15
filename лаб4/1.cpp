#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
struct Student{
	string fio;
	string clas;
	int marks;
	int m[5];
	float avg;
};

Student list[5];
int current_size = 0, sum = 0, mark[5], n = 2, choice;
float average = 0, aveg[5], a;

void enterNew(){
	
	cout << "ввод информации" << endl;
	for (int i = 0; i < n; i++) {
		
		cout << "Enter fio:";
		cin >> list[i].fio;
		
		cout << "Enter class:";
		cin >> list[i].clas;
		
		cout << "Enter marks:";
		for (int j = 0; j < 5; j++ ){
			cin >> list[i].marks;
			if (list[i].marks < 11) {
				mark[j] = list[i].marks;
				list[i].m[j] = mark[j];
				average += mark[j];
			}
			else {
				cout << "incorrect mark" << endl;
				cin >> list[i].marks;
				mark[j] = list[i].marks;
				list[i].m[j] = mark[j];
				average += mark[j];
			}
		}
		average /= 5;
		aveg[i] = average;
		average = 0;
	}
	
	for (int i = 0 ; i < n; i++) {
		list[i].avg = aveg[i];
	}

}

void out(){
	
	cout << "вывод информации" << endl;
	for (int i = 0; i < n; i++){
		cout << list[i].fio << "; ";
		cout << list[i].clas << "; ";
		if (list[i].avg > 10) {
			cout << "Такого быть не может";
			list[i].avg = 0;
		}
		cout << list[i].avg << "; ";
		for (int j = 0; j < 5; j++) {
			cout << list[i].m[j] << ", ";
		}
		cout << endl;
	}
		
}

void del(){
	cout << "удаление записи" << endl;
	int numb;
	cin >> numb;
	if (numb != 0) {
		
		for (int i = (numb-1); i < n; i++) {
			list[i] = list[i-1];
			list[i] = list[i+1];
		}
		n--;
	}
	else {
		cout << "такой строки нет";
		cin >> numb;
	}
}

void search(){
	cout << "поиск" << endl;
	cout << "введите средний балл" << endl;
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a == list[i].avg) {
			cout << list[i].fio << "; " << list[i].clas << "; " << list[i].avg  << "; ";
			for (int j = 0; j < 5; j++) {
				if (j == 4)
					cout << list[i].m[j] << ".";
				else
					cout << list[i].m[j] << ", ";			
			}
		}
	}
}

void writeIntoTheFile(){
	cout << "запись в файл" << endl;
	ofstream fout;
	fout.open("test.txt");
	for (int i = 0; i < n; i++) {
		fout << list[i].fio << "; " << list[i].clas << "; " << list[i].avg  << "; ";
		for (int j = 0; j < 5; j++) {
			if (j == 4){
				fout << list[i].m[j] << ".";
				cout << endl;
			}
			else
				fout << list[i].m[j] << ", ";
		}
		fout << endl;
	}
}

void outOfTheFile(){
	string str;
	ifstream file1("test.txt");
	while (file1) {
		getline(file1, str);
		cout << str << endl;
	}
}

int main() {
	do
		{
			setlocale(LC_CTYPE, "Russian");
			cout << "введите:" << endl;
			cout << "1-для ввода записи" << endl;
			cout << "2-для вывода записи" << endl;
			cout << "3-для удаления" << endl;
			cout << "4-для поиска информации" << endl;
			cout << "5-для записи в файл" << endl;
			cout << "6-для чтения из файла" << endl;
			cout << "7-для выхода" << endl;
			
			cin >> choice;
			switch (choice)
			{
				case 1: enterNew(); break;
				case 2: out(); break;
				case 3: del(); break;
				case 4: search(); break;
				case 5: writeIntoTheFile(); break;
				case 6: outOfTheFile();break;
				
			}
		} 
	while (choice != 7);
	return 0;
}