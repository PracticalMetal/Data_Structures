#include <iostream>  
 
using namespace std;
 

void bubble_sort(int A[], int n)
{
    int flag; // to make the sort adaptive and check if any swaps were done or not

    for(int i=0;i<n-1;i++)
    {   flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            // here j is less than n-1-i because in every compariosion we get the biggest element sorted at the end so we can avoid that comparision
            if(A[j]>A[j+1])
            {
                flag=1;
                swap(A[j],A[j+1]);
            }
        }
        if(flag==0)break;
    }
}


void insertion_sort(int A[], int n)
{
    for(int i=1;i<n;i++) // assuming the first element is already sorted
    {
        int j=i-1;
        int x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;

    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    insertion_sort(A,n);   
    for(int x:A)cout<<x<<" ";
}