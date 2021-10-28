#include <iostream>

using namespace std;

//Factorial using recursive funtions

int fact(int n)
{
	if (n == 0)return 1;
	else
		return n * fact(n - 1);
}

//Power using recursive method
int power(int m, int n)
{
	if (n == 0)return 1;
	else if (n % 2 == 0)return power(m * m, n / 2);
	else return m * power(m * m, (n - 1) / 2);
}

//Taylor series using recursive function

double taylor(int x, int n)
{
	if (n == 1)return 1;

	double a, b;
	a = (power(x, n - 1)) / fact(n - 1);
	b = taylor(x, n - 1);
	double r = a + b;
	return r;





}




double taylor2(int x, int n)
{
	static double p = 1, f = 1;
	double r;

	if (n == 0)return 1;
	r = taylor2(x, n - 1);
	p *= x;
	f *= n;
	return r + p / f;
}








//Addition of natural number using recursive function

int add(int n)
{
	if (n == 1)return 1;
	else return n + add(n - 1);
}

int main()
{

	cout << taylor2(1, 1);


}