#include <iostream>  
#include <vector>
#include <algorithm> 
using namespace std;



//Displaying a vector
void print_vect(vector<int> arr)
{
    vector<int>::iterator iter;

    for(iter=arr.begin();iter!=arr.end();iter++)
    cout<<*iter<<" ";
    cout<<endl;
}

//Union
vector<int> Union(vector<int> arr1,vector<int> arr2)
{
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    iter1=arr1.begin();
    iter2=arr2.begin();

    vector<int> arr3;

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());


    while(iter1!=arr1.end() && iter2!=arr2.end())
    {
        if((*iter1)<(*iter2))
        {
            arr3.push_back(*iter1);
            //arr3.push_back(*iter2);
            iter1++;
            //iter2++;
        }
        else if((*iter1)>(*iter2))
        {
            arr3.push_back(*iter2);
            iter2++;
        }
        else
        {
            arr3.push_back(*iter1);
            iter1++;
            iter2++;

        }
    }

    for(;iter1!=arr1.end();iter1++)
    arr3.push_back(*iter1);

    for(;iter2!=arr2.end();iter2++)
    arr3.push_back(*iter2);

    return arr3;

}



//Intersection

vector<int> Intersection(vector<int> arr1,vector<int> arr2)
{
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    iter1=arr1.begin();
    iter2=arr2.begin();

    vector<int> arr3;

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());


    while(iter1!=arr1.end() && iter2!=arr2.end())
    {
        if((*iter1)<(*iter2))
        {
            //arr3.push_back(*iter1);
            //arr3.push_back(*iter2);
            iter1++;
            //iter2++;
        }
        else if((*iter1)>(*iter2))
        {
            //arr3.push_back(*iter2);
            iter2++;
        }
        else
        {
            arr3.push_back(*iter1);
            iter1++;
            iter2++;

        }
    }

    

    return arr3;
}

vector<int> Difference(vector<int> arr1,vector<int> arr2)
{
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    iter1=arr1.begin();
    iter2=arr2.begin();

    vector<int> arr3;

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());


    while(iter1!=arr1.end() && iter2!=arr2.end())
    {
        if((*iter1)<(*iter2))
        {
            arr3.push_back(*iter1);
            //arr3.push_back(*iter2);
            iter1++;
            //iter2++;
        }
        else if((*iter1)>(*iter2))
        {
            //arr3.push_back(*iter2);
            iter2++;
        }
        else
        {
            //arr3.push_back(*iter1);
            iter1++;
            iter2++;

        }
    }

    for(;iter1!=arr1.end();iter1++)
    arr3.push_back(*iter1);

    

    return arr3;

}

 
int main()
{
    vector<int> arr1,arr2;
    for(int i=1;i<10;i++)
    {
        arr1.push_back(i);
        arr2.push_back(i+5);
    }

    vector<int> arr3;
    arr3=Difference(arr1,arr2);
    print_vect(arr3);

}