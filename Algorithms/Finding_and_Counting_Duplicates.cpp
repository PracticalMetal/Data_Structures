#include <iostream>  
 
using namespace std;
 
int main()
{
    int n;
    
    cout<<"Enter the number of elements\n";
    cin>>n;

    int arr[n];
    for(int &x:arr)
    cin>>x;

    // int last_element;

    // for(int i=0;i<n-1;i++)
    // {
    //     if(arr[i]==arr[i+1] && arr[i]!=last_element)
    //     {
    //         last_element=arr[i];
    //         cout<<arr[i]<<" ";
    //     }
    // }


    //Counting number of duplicates

    int j=0;

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        j++;
        else
        {
            if(j!=0)
            cout<<arr[i]<<" appeared "<<j+1<<" times\n";                   /* order of n*/
            j=0;
        }
    }
}