#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Russian");
	ifstream fin;

	fin.open("f.txt");

	if (!fin.is_open())
		cout << "Файл не может быть открыт" << endl;

	else {

		int num = 0, index = 0, count = 0, j = 0, arr[50];
		string buff;
		
		while (!fin.eof()) {
			
			getline(fin,buff);
			for ( string::size_type i = 0; i < buff.size(); i++)
			{
				if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' || buff[i]== 'y')
					count++;
			}
			
			arr[j] = count;
			count = 0;
			j++;
		}
		
		fin.close();
		
		
		int max = arr[0];

		for (int i = 0; i < j; i++){
			
			if (max < arr[i]) {
				max = arr[i];
				index = i;
			}
		}
		
		cout << index;
		ofstream fout;
		fout.open("out.txt");
		
		fin.open("f.txt");
		string line_file_text;
		while (getline(fin, buff)) {
			if (num != index)
				fout << buff << endl;
			num++;
		}
		fin.close();
		
	}

	
	return 0;
}