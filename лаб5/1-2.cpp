#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
int n = 2;


union avia{
	int number;
	char destination[10] = "";
	float costd;
};

struct t{
	unsigned int array_date : 16;
};
t list;

enum places{
	Moscow= 1245, Paris = 5432, London= 4156, Berlin= 5784
}ans;

union avia perem;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string amount;
int array_numb[5];
float array_cost[5];
int array_seats[5];
string array_place[5];
string array_time[5];
string ar_date[5];
string a;

string str1 = "";
string str2 = "";
string str3 = "";
int count =  0;
int g;
bool flag = false;



int time1(string time){
	int index = 0, num = 0, num2 = 0;
	string str1 = "", str2 = "";
	for (string::size_type j = 0; j < time.size(); j++) {
		if (time[j] == '.') {
			index = j;
		}
	}
	for (string::size_type j = 0; j < index; j++) {
		str1 += time[j];
		num = stoi(str1);
	}
	
	return num;
}

int time2(string time){
	int index = 0, num2 = 0;
	string str2 = "";
	
	for (string::size_type j = 0; j < time.size(); j++) {
		if (time[j] == '.') {
			index = j;
		}
	}
	
	for (string::size_type j = index+1; j < time.size(); j++) {
		str2 += time[j];
		num2 = stoi(str2);
	}
	return num2;
}

void enterNew(){
	for (int i = 0; i < n; i++) {
		
		cout << "Form of flyes(1 - Moscow, 2 - Paris, 3- London, 4 - Berlin): ";
		int form;
		do {
			cin >> form;
			if (form < 1 or form > 4)
				cout << "Incorrect Input";
		} while (form < 1 or form > 4);
		if (form == 1){
			array_numb[i] = (int)Moscow;
			array_place[i] = "Moscow";
		}
		if (form == 2){
			array_numb[i] = (int)Paris;
			array_place[i] = "Paris";
		}
		if (form == 3){
			array_numb[i] = (int)London;
			array_place[i] = "London";
		}
		if (form == 4){
			array_numb[i] = (int)Berlin;
			array_place[i] = "Berlin";
		}
		
		cout << "Enter departure time:";
		cin >> perem.destination;
		array_time[i] = perem.destination;
		
		while (time1(array_time[i]) < 0 || time1(array_time[i]) > 23 || time2(array_time[i]) < 0 || time2(array_time[i]) > 59) {
			cout << "Incorrect time, please rewrite ur time" << endl;
			cout << "Enter departure time:";
			cin >> perem.destination;
			array_time[i] = perem.destination;
		}
		
		cout << "Enter data:";
		cin >> g;
		
		list.array_date = g;
		
		int year = g % 10000;
		int day = g / 1000000;
		int month = g / 10000 % 100;
		
		while (month < 1 || month > 12) {
			list.array_date = 0;
			g = 0;
			
			year = 0;
			day = 0;
			month = 0;
			
			cout << "Incorrect month" << endl;
			cout << "Enter data:";
			cin >> g;
			
			
			year = g % 10000;
			day = g / 1000000;
			month = g/ 10000 % 100;
			
		}
		
		while (flag != true) {
			for (int i = 0; i < 12; i++) {
				if (month == i+1) {
					if (day > days[i]) {
						cout << day << endl;
						day = 0;
						cout << "Incorrect day" << endl;
						cin >> day;
					}
					else {
						str3 += to_string(day);
						str3 += '.';
						flag = true;
					}
				}
			}
		}
		
		flag = false;
		str3 += to_string(month);
		str3 += '.';
		str3 += to_string(year);
		ar_date[i] = str3;
		str3.clear();
		
		cout << "Enter cost:";
		cin >> perem.costd;
		array_cost[i] = perem.costd;
		
		cout << "Enter number of seats:";
		cin >> perem.number;
		array_seats[i] = perem.number;
	}
}

void out(){
	cout << "Вывод" << endl;
	for (int i = 0 ; i < n; i++) {
		cout << array_numb[i] << ' ' << array_place[i] << ' ' << array_time[i] << ' ' << ar_date[i]<< ' ' << array_cost[i] << ' ' << array_seats[i];
		cout << endl;
	}
}

void del(){
	cout << "удаление записи" << endl;
	int numb;
	cin >> numb;
	if (numb != 0) {
		
		for (int i = (numb-1); i < n; i++) {
			
			array_numb[i] = array_numb[i-1];
			array_numb[i] = array_numb[i+1];
			
			array_place[i] = array_place[i-1];
			array_place[i] = array_place[i+1];
			
			array_time[i] = array_time[i-1];
			array_time[i] = array_time[i+1];
			
			ar_date[i] = ar_date[i-1];
			ar_date[i] = ar_date[i+1];
			
			array_cost[i] = array_cost[i-1];
			array_cost[i] = array_cost[i+1];
			
			array_seats[i] = array_seats[i-1];
			array_seats[i] = array_seats[i+1];
		}
		n--;
	}
	else {
		cout << "такой строки нет";
		cin >> numb;
	}
}

void search(){
	cout << "Поиск" << endl;
	cin >> amount;
	for (int i = 0 ; i < n; i++) {
		if (amount == ar_date[i]) {
		cout << array_numb[i] << ' ' << array_place[i] << ' ' << array_time[i] << ' ' << ar_date[i]<< ' ' << array_cost[i] << ' ' << array_seats[i];
		cout << endl;
		}
	}
}
	
void writeIntoTheFile(){
	cout << "запись в файл" << endl;
	ofstream fout;
	fout.open("test2.txt");
	for (int i = 0 ; i < n; i++) {
		fout << array_numb[i] << ' ' << array_place[i] << ' ' << array_time[i] << ' ' << ar_date[i]<< ' ' << array_cost[i] << ' ' << array_seats[i];
			fout << endl;
		}
}

void outOfTheFile(){
	string str;
	ifstream file1("test2.txt");
	while (file1) {
		getline(file1, str);
		cout << str << endl;
	}
}

int main() {
	int choice;
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