#include <iostream>
using namespace std;


int fmax(int n, ...) {
	int* p = &n;
	p = p + 1;
	int max_number = 0;
	for (int i = 0; i < n * 2; i += 2) {
		if (*(p + i) > max_number)
			max_number = *(p + i);
	}
	return max_number;
}

int main() {

	cout << fmax(5, 4, 3, 6, 1, 8);
}