#include <iostream>
void sum(int n, ...);
using namespace std;

int main(){
	sum(6, 4, 5, 1, 2, 3, 0);
	return 0;
}
void sum(int n, ...)
{
	int arr[n];
	int *p = &n;
	int sum = 0;
	*(++p);
	for(int i=1; i<=n; i+=2)
		arr[i] = *(p);
		
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}