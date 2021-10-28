#include<iostream>

using namespace std;

//double p=1,f=1;


double taylor(double x, int n)
{	static double p = 1, f = 1;
	double r;
	if (n == 0) {
		p = 1; f = 1;
		return 1;
	}
	else
	{
		r = taylor(x, n - 1);
		p *= x;
		f *= n;
		return r + p / f;
	}
}



int main()
{
	//taylor series using recursion

	cout << taylor(1, 100) << endl;
	cout << taylor(1, 100);
}