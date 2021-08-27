#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int Min,Max;

    int arr[]={1,2,3,4,5,5,5,5,5,100,11,12};

    Max=Min=arr[0];

    for(int i=1;i<12;i++)
    {
        if(arr[i]>Max)
        Max=arr[i];

        if(arr[i]<Min)
        Min=arr[i];


    }

    cout<<Max<<" "<<Min;

    
}