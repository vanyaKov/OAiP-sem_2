#include <iostream>
using namespace std;


int fmin(int n, ...) {
	int* p = &n;
	p = p + 1;
	int min_number = 1000;
	for (int i = 0; i < n*2; i+=2) {
		if (*(p + i) < min_number)
			min_number = *(p + i);
	}
return min_number;
}
int main(){
	cout<<fmin(5, 4, 3, 6, 1, 8) <<endl;
	return 0;
}