#include<iostream>
#include<math.h>

using namespace std;


//For loop for taylor series using homer rule

double e(int x, int n)
{
	double s = 1; //Using s=1 because for the last function(assuming that there is a term (1+x^4/4)it will be multiplied by 1 )
	for (; n > 0; n--)
	{
		s = 1 + (float)x / n * s;

	}
	return s;
}


//Recursive function for taylor series using homer rule

double taylor(int x, int n)
{
	static double s1 = 1;
	if (n == 0)
	{

		return s1;
	}
	else
	{
		s1 = 1 + (float)x / n * s1 ;
		return taylor(x, n - 1);
	}
}

int main()
{
	// cout << e(1, 5) << endl;
	// cout << taylor(1, 5) << endl;
	// cout << taylor(1, 5);
	cout << sin(90);                                     //here the parameter is in radians



}
