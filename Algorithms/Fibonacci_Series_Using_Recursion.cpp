#include<iostream>

using namespace std;

/*Fibonacci Series*/

//Iterative

int fib1(int n)
{	int p2 = 0, p1 = 1;
	if (n == 0)return p2;
	else if (n == 1)return p1;
	else
	{	int sum = 0;
		for (int i = 0; i <= n - 2; i++)
		{


			sum = p2 + p1;
			p2 = p1;
			p1 = sum;


		}
		return sum;
	}
}


//Recursive
int fib2(int n)
{	static int sum = 0;
	static int p2 = 0, p1 = 1;
	if (n == 0)return 0;
	else if (n == 1)return sum;
	else
	{

		sum = p2 + p1 ;
		p2 = p1;
		p1 = sum;
		return fib2(n - 1);
	}

}


int fib3(int n)
{
	if (n <= 1)return n;
	else
		return fib3(n - 2) + fib3(n - 1);   /*Time complexity= O(2^n)*/
}

int main()
{
	cout << fib1(7) << endl;
	cout << fib2(7) << endl;
	cout << fib3(7);
}