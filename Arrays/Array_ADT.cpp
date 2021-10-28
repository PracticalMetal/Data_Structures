#include<bits/stdc++.h>


using namespace std;



struct Array
{
	int *a;
	int length, size;


};

void display(Array r);
void insert(Array *r, int index, int x);
void Append(Array *r, int x);
void Delete(Array *r, int index);
int linearSearch(Array *r, int key);
int binarySearchIterative(Array r, int key);
int binarySearchRecursive(int l, int h, Array r, int key);
int get(int index, Array r);
string set(int index, Array *r, int x);
int Max(Array r);
int Min(Array r);
int sum(Array r);
int sumRecursive(Array r, int n);
int average(Array r);
void reverse(Array *r);
void shift(Array *r);
void insertInSorted(Array *r, int value);
bool isSorted(Array r);
void leftForNegative(Array *r);
struct Array* array_merge(Array *arr1,Array *arr2);





int main()
{
	Array arr1;
	cout << "Enter the size of the array" << endl;
	cin >> arr1.size;
	arr1.a = new int[arr1.size];
	arr1.length = 0;

	int n1;
	cout << "Enter the number of numbers" << endl;
	cin >> n1;
	cout<<"Enter all the elements"<<endl;
	for (int i = 0; i < n1; i++)
	{
		cin >> arr1.a[i];
	}

	Array arr2;
	cout << "Enter the size of the array" << endl;
	cin >> arr2.size;
	arr2.a = new int[arr2.size];
	arr2.length = 0;

	int n2;
	cout << "Enter the number of numbers" << endl;
	cin >> n2;
	cout<<"Enter all the elements"<<endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> arr2.a[i];
	}


	arr1.length = n1;
	arr2.length = n2;

	Array *arr3;
	arr3=array_merge(&arr1,&arr2);
	display(*arr3);

	// system("clear");


	// cout<<setw(50)<<"Menu \n\n";
	// cout<<"1."<<setw(10)<<"Insert"<<endl;
	// cout<<"2."<<setw(10)<<"Delete"<<endl;
	// cout<<"3."<<setw(10)<<"Search"<<endl;
	// cout<<"4."<<setw(10)<<"Sum"<<endl;
	// cout<<"5."<<setw(10)<<"Display"<<endl;
	// cout<<"6."<<setw(10)<<"Exit"<<endl;

	// cout<<setw(50)<<"Enter your choice"<<endl;

	// int choice;
	// cin>>choice;
		







}


void display(Array r)
{
	for (int i = 0; i < r.length; i++)
	{
		cout << r.a[i] << " ";
	}
	cout << endl;
}

void insert(Array *r, int index, int x)
{
	int check = true;

	if (index > r->length || index > r->size)
		check = false;

	if (check != false)


	{	for (int i = r->length; i > index; i--)
		{
			r->a[i] = r->a[i - 1];
		}
		r->a[index] = x;
		r->length++;
	}

	else
		cout << "Invalid Input" << endl;
}

void Append(Array *r, int x)
{
	if (r->length < r->size)
	{
		r->a[r->length] = x;
	}
	r->length++;
}


void Delete(Array *r, int index)
{
	for (int i = index; i < r->length; i++)
	{
		r->a[i] = r->a[i + 1];
	}
	r->length--;
}

int linearSearch(Array *r, int key)
{
	for (int i = 0; i < r->length; i++)
		if (r->a[i] == key)
			return i;

	return -1;

}

int binarySearchIterative(Array r, int key)
{
	int l, mid, h;
	l = 0;
	h = r.length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;

		if (r.a[mid] == key)
			return mid;
		else if (r.a[mid] > key)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return -1;



}

int binarySearchRecursive(int l, int h, Array r, int key)
{
	if (l <= h)
	{
		int mid = (l + h) / 2;
		if (r.a[mid] == key)
			return mid;
		else if (key > r.a[mid])
			return binarySearchRecursive(mid + 1, h, r, key);
		else
			return binarySearchRecursive(l, mid - 1, r, key);
	}
	return -1;

}

int get(int index, Array r)
{
	if (index >= 0 && index < r.length)
		return r.a[index];
	return -1;
}

string set(int index, Array *r, int x)
{
	if (index >= 0 && index < r->length)
	{
		r->a[index] = x;
		return "Replaced";
	}
	return "Not found!";

}

int Max(Array r)
{
	int Max = r.a[0];
	for (int i = 1; i < r.length; i++)
	{
		if (r.a[i] > Max)
			Max = r.a[i];
	}
	return Max;
}

int Min(Array r)
{
	int Min = r.a[0];
	for (int i = 1; i < r.length; i++)
	{
		if (r.a[i] < Min)
			Min = r.a[i];
	}
	return Min;
}

int sum(Array r)
{
	int sum = 0;
	for (int i = 0; i < r.length; i++)
	{
		sum += r.a[i];
	}
	return sum;
}

int sumRecursive(Array r, int n)
{
	if (n > 0)
		return 0;
	else
		return sumRecursive(r, n - 1) + r.a[n];
}

int average(Array r)
{
	int avg;
	avg = sum(r);
	return (float)avg / r.length;
}

void reverse(Array *r)
{
	for (int i = 0, j = r->length - 1; i <= j; i++, j--)
		swap(r->a[i], r->a[j]);
}

void insertInSorted(Array *r, int value)
{

	int i = r->length - 1;
	r->a[i + 1] = value;

	while (r->a[r->a[i]] > r->a[r->a[i + 1]])
		swap(r->a[i], r->a[r->a[i + 1]]);
	r->length++;

}

bool isSorted(Array r)
{
	int l = r.length;
	for (int i = 0; i < l - 1; i++)
	{
		if (r.a[i] > r.a[i + 1])
			return false;
	}
	return true;
}

void leftForNegative(Array *r)
{
	int i = 0, j = r->length - 1;
	while (i < j)
	{
		while (r->a[i] < 0) {i++;}
		while (r->a[j] >= 0) {j--;}
		if (i < j)
		{
			swap(r->a[i], r->a[j]);
		}
	}
}

struct Array* array_merge(Array *arr1,Array *arr2)
{
int i,j,k;
i=j=k=0;
 
Array *arr3=new Array;
arr3->a=new int[arr1->length+arr2->length];// this line missing
//assuming array to be sorted
 
while(i<arr1->length && j<arr2->length)
{
if(arr1->a[i]<arr2->a[j])
arr3->a[k++]=arr1->a[i++];
else
arr3->a[k++]=arr2->a[j++];
}
 
for(;i<arr1->length;i++)
arr3->a[k++]=arr1->a[i];
 
for(;j<arr2->length;j++) //it shold be j++
arr3->a[k++]=arr2->a[j];
 
arr3->size=arr3->length=arr1->length+arr2->length;
 
return arr3;
}
