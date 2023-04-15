#include <iostream>
#include <math.h>
using namespace std;


double equation7(double n) {
	double root = pow(n, 3) + n - 3;
	return root;
}

double equation8(double n) {
	double root = pow(cos(n), 3);
	return root;
}

double getTheRoot4(double (*equation)(double), double a, double b) {
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

	cout << getTheRoot4(equation7, a, b) << endl;
	cout << getTheRoot4(equation8, a, b);
	return 0;
}