#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
	
	FILE *file1 = fopen("matrix1.txt", "r");
	FILE *file2 = fopen("matrix2.txt", "r");

	int a[0];
	for (int i = 0 ; i < 1 ; i++) 
		fscanf(file1, "%d", &a[i]);
	int f = a[0];
	int matr1[f][f], matr2[f][1], matr3[f][1];
	
	for (int i = 0 ; i < f; i++){
		for (int j = 0 ; j < f; j++){
			fscanf(file1, "%d", &matr1[i][j]);
		}
	}
	
	for (int i = 0 ; i < f; i++){
			fscanf(file2, "%d", &matr2[i][0]);
	}
	
	for (int i = 0 ; i < f; i++){
		for (int j = 0 ; j < 1; j++){
			matr3[i][j] = matr1[i][j] * matr2[i][j];
		}
	}
	
	for (int i = 0 ; i < f; i++){
		for (int j = 0 ; j < 1; j++){
			cout << matr3[i][j]<< endl;
		}
	}
	
	fclose(file1);
	fclose(file2);
	return 0;
}