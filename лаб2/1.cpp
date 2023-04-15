#include <iostream>
#include <stdio.h>
using namespace std;

const int n = 10;
const int half = 5;

int main(int argc, char *argv[]) {
	FILE *file = fopen("test.txt", "r");
	
	
	int ar[50], i = 0, s = 0;
	
	while (!feof(file)) {
		fscanf(file, "%d", &ar[i]);
		i++;
		s++;
	}
	
	for (int j = 0; j < s/2; j++) {
		if (j == 0) 
			cout <<  ar[j] << ' ' << ar[(s-1)-j]  << ' ';
		else 
			cout << ar[j] << ' ' << ar[(s-1)-j] << ' ';
	}
	
	fclose(file);
	return 0;
}