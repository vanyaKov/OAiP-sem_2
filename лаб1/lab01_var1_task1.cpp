#include <iostream>
#include <math.h>
using namespace std;


double equation3(double n) {
	double root = sin(n) + 0.1;
	return root;
}

double equation4(double n) {
	double root = pow(n, 2) + 4*n -2 ;
	return root;
}

double getTheRoot2(double (*equation)(double), double a, double b) {
	double x = 0;
	float e = 0.001;
	double f1, f2;
	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		f1 = equation(x);
		f2 = equation(a);
		if (f1 * f2 <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

int main() {
	int a;
	int b;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	cout << getTheRoot2(equation3, a, b) << endl;
	cout << getTheRoot2(equation4, a, b);
	return 0;
}