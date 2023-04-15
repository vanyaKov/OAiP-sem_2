#include <iostream>

using namespace std;

void min(int n,...){
	va_list  number;
	va_start(number, n);
	
	
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = va_arg(number, int);
	}
	
	
	int min = arr[0];
	
	for (int i = 1; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	
	cout << min;
	va_end(number);
	
}


int main() {
	min(6, 1, 2, -5, 3);
	return 0;
}