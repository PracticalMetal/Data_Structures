#include <iostream>  
 
using namespace std;
 
struct Array
{
    int size,length;
    int *a;
};

void create(Array *arr,int size)
{
    arr->size=size;
    arr->length=0;
    arr->a=new int[arr->size];
}

void insert_elements(Array *arr, int n)
{
    if(n>arr->size)return;
    else
    {
        for(int i=0;i<n;i++)cin>>arr->a[i];
    }
    arr->length=n;
}

void display(Array arr)
{
    for(int i=0;i<arr.length;i++)cout<<arr.a[i]<<" ";
} 

void insert(Array *arr,int data, int pos=0)
{
    if(pos>arr->length || pos>arr->size)return ;
    for(int i=arr->length;i>pos;i--)
    arr->a[i]=arr->a[i-1];
    arr->a[pos]=data;
    arr->length++;
}

void append(Array *arr, int data)
{
    if(arr->length==arr->size)return ;
    else
    {
        arr->a[arr->length]=data;
        arr->length++;
    }
}

void Delete(Array *arr, int pos)
{
    if(pos>arr->length-1)return;
    for(int i=pos;i<arr->length-1;i++)arr->a[i]=arr->a[i+1];
    arr->length--;
}

int binary_search(Array *arr, int key)
{
    int mid;
    int l=0,h=arr->length-1;
    
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr->a[mid]==key)return mid;
        else if(key>arr->a[mid])l=mid+1;
        else h=mid-1;
    }
    return -1;
} 

int main()
{
    Array array_1;
    create(&array_1,10);
    insert_elements(&array_1,5);
    cout<<binary_search(&array_1,11);

}