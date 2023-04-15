#include <iostream>

using namespace std;

double Dihotomy(double eps)
{
	
	double c, a = 0, b = 5;
	
	if (eps < 0 || eps == 0)
		{
			cout << "Неверно заданное приближение";
		}
	if (func(a) * func(b) < 0)
		{
			c = a + b / 2;
			a = c;
		}
	else
		{
			c = a + b / 2;
			b = c;
		}
	return (b - a < eps) ? c : Dihotomy(eps);
}

static public double func(double x)
{
	return Math.Pow(x, 2) - 2;
}

int main(int argc, char *argv[]) {
	
}