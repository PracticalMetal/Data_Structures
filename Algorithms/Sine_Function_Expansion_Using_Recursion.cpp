#include<iostream>
#include<math.h>

#define PI 3.1415

using namespace std;


/*Sine function using taylor series*/

//Iteration

int fact(int n)
{
	if (n == 0)return 1;
	else
	{
		return n * fact(n - 1);
	}
}

double sine1(double ang_in_degree, int n)
{
	double y = ang_in_degree * PI / 180;
	double s = 0;


	for (; n > 0; n--)
	{
		s += pow(-1, n - 1) * pow(y, 2 * n - 1) / fact(2 * n - 1);

	}

	return s;



}


//Recursive Function

double sine2(double ang_in_degree, int n)
{	double y = ang_in_degree * PI / 180;;
	static double s = 0;
	if (n == 0)return s;
	else
	{
		s += pow(-1, n - 1) * pow(y, 2 * n - 1) / fact(2 * n - 1);
		return sine2(ang_in_degree, n - 1);
	}

}




int main()
{

	cout << sine1(45.0, 5) << endl;
	cout << sine2(45.0, 5);



}