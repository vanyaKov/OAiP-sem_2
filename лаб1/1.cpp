#include <iostream>
#include <cmath>
using namespace std;

double equation1(double x){
	
	double eqv = pow(x, 3) + 3*x -1;
	return eqv;
}

double equation2(double x){
	
	double eqv = exp(x) - 4;
	return eqv;
}

void dih(double(*equation)(double), double a, double b){
	double result;
	float e = 0.001;
	while (abs(a-b) > 2*e)
		{
			double x = (a + b) / 2;
			double fx = equation(x);
			double fa = equation(a);
			
			if (fx*fa <= 0)
				b = x;
			else
				a = x;
			
			result = x;
		}
	cout << result << endl;
}

int main() {
	int a, b;
	cin >> a >> b;
	dih(equation1, a, b);
	dih(equation2, a, b);
	
	
	return 0;
}