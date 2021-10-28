#include <iostream>  
 
using namespace std;
 
int main()
{
    //Single element in a sorted array 

    int arr[]={1,2,3,4,5,6,8,9,10,11};
    
    for(int i=1;i<9;i++)
    if(arr[i+1]!=arr[i]+1)
    {cout<<arr[i]+1<<" is missing!"<<endl;}
   

    
}