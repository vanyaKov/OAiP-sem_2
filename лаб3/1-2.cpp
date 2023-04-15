#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
	
	string buff;
	string str1 = "", str2 = "";
	
	ofstream fout;
	
	fout.open("second.txt");
	
	getline(cin, buff);
	fout << buff;
	fout.close();
	
	ifstream fin;
	fin.open("second.txt");
	
	int point = 0, k = 0;
	char arr[100];
	int s = 0;
	
	while (!fin.eof()) {
		
		getline(fin,buff);
		
		for ( string::size_type i = 0; i < buff.size(); i++){
			s++;
			if(buff[i] == '.'){
				point = i;
			}
		}
		if(!point){
			cout << "Нет вещественного числа";
			break;
		}
			
		int pos = point - 1;
		int pos2 = point + 1;
	
		for (int i = pos; i > -1; i--) {
			if (isdigit(buff[i]))
				str1 += buff[i];
			else 
				break;
				
		}
			
		reverse(str1.begin(), str1.end());
			
		for (int i = pos2; i < buff.size(); i++) {
			if (isdigit(buff[i]))
				str2 += buff[i];
			else 
				break;
		}
			
		if (str1 == "" || str2 == "") {
			cout << "Нет вещественного числа";
			break;
		}
		
		cout << str1 << '.' << str2;
	}
	
	return 0;
}