#include<iostream>

using namespace std;

int binarySearch(int key, int arr[], int n);

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int key = 39;

	cout << binarySearch(key, arr, 5);


}

int binarySearch(int key, int arr[], int n)
{
	int l, h;
	l = 0;
	h = n - 1;

	int mid;


	while (l <= h)
	{
		mid = (l + h) / 2;
		if (arr[mid] == key)
		{return mid;}

		else if (key > arr[mid])
		{
			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}

	}

	return -1;

}
