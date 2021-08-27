#include <iostream>
using namespace std;

float add(int a, int b)
{
	return (float)(a / b) + (float)b / a;
}

int main()
{
	cout << add(4, 3);
}