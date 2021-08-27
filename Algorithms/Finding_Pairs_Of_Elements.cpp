#include <iostream>  
#include<vector> 
 
using namespace std;
 
int main()
{
    vector<int> arr;

    for(int i=1;i<=10;i++)
    {
        
        arr.push_back(i);
    }

    int H[11]={0};

    for(int i=0;i<10;i++)
    {
        H[arr[i]]++;
        int s=10-arr[i];
        if(H[s]!=0)
        cout<<arr[i]<<"+"<<10-arr[i]<<"\n";
    }

}