#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> arr = {{1, 2, 3}, {1, 2}};

	for (unsigned int i = 0; i < arr.size(); i++)
	{	for (int x : arr[i])
			cout << x << ",";
		cout << endl;
	}








}

