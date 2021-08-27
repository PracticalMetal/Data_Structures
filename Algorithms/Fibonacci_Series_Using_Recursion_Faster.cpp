#include<iostream>

using namespace std;


int fib(int n)
{
	static int check[15];
	if (n <= 1)
	{
		//check[n] = n;
		return n;

	}

	else
	{
		if (check[n - 2] == -1)check[n - 2] = fib(n - 2);
		if (check[n - 1] == -1)check[n - 1] = fib(n - 1);
		return fib(n - 2) + fib(n - 1);
	}
}

int main()
{
	cout << fib(1);
}