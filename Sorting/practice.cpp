#include <iostream>  
 
using namespace std;


void bubble_sort(int A[], int n)
{
    // to make the sort adaptive that is of order O(n)
    int flag;

    // first loop is for passes
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        // second loop is for iterations
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;
                swap(A[j],A[j+1]);
            }
        }
        if(flag==0)break;
    }
    // time : min- O(n)   max- O(n^2)
    // adaptive: yes
    // stable: yes
    // first k iterations gives highest k elements
}


void insertion_sort(int A[], int n)
{
    // outer loop is for the element that has to be inserted into the assumed sorted list
    for(int i=1;i<n;i++)
    {   
        // j will hold the last element of the sorted list
        int j=i-1;
        // x will hold the unsorted element which has to be inserted
        int x=A[i];

        while(A[j]>x && j>-1)
        {
            // here we will shift the element to as to reach the place for the element
            A[j+1]=A[j];
            j--;
        }
        // j+1 because in the while loop j will reach the position before the required position
        A[j+1]=x;
    }
    // time : min- O(n)   max-O(n^2)
    // adaptive: yes(through its own algo)
    // stable : yes
    // first k interations wont give any useful result
    // only bubble and insertion sort are adaptive
}


void selection_sort(int A[], int n)
{
    int i,j,k;
    // outer loop is for passes and its n-1 because the last element will find a sorted place during the last last (n-1)th iteration
    for(i=0;i<n-1;i++)
    {
        // outer loop is for finding the smallest element
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])k=j;
        }
        swap(A[i],A[k]);
    }
    // time : O(n^2)
    // adaptive: no
    // stable: no
    // first k iteration gives smallest k elements
}


int partition(int A[], int l, int h)
{
    // setting the pivot as the low element
    // note:  quick sort will work only when there are minimum 2 elements
    int pivot=A[l];
    int i=l;
    int j=h;

    do
    {
        do
        {
            i++;
        } while (A[i]<=pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        // swapping elements so as to get the smaller element to the left and larger to the right    
        if(i<j)swap(A[i],A[j]);        
    } while (i<j);
    // swapping the pivot so as to sort that element in its position
    swap(A[l],A[j]);
    return j;
}

void quick_sort(int A[], int l, int h)
{   
    int j;
    // this is the terminating condition and will check if there are atleast 2 elements
    if(l<h)
    {
        j=partition(A,l,h);
        quick_sort(A,l,j);
        quick_sort(A,j+1,h);
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2, INT32_MAX},n=11;
    quick_sort(A,0,10);
    for(int x:A)cout<<x<<" ";
}