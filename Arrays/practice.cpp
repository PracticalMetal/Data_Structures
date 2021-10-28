#include <bits/stdc++.h>  
 
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
    // time : O(n)
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

    // time : O(logn)
} 

int _get(Array arr,int index)
{
    if(index<0 || index>arr.length)return -1;
    else return arr.a[index];

    // time : O(1)
}

int rSum(Array arr, int n)
{
    if(n<0)return 0;
    else return arr.a[n]+rSum(arr,n-1);
}

void _reverse(Array *arr)
{
    for(int j=arr->length-1,i=0;i<=j;i++,j--)swap(arr->a[i],arr->a[j]);
    // time : O(n)
}

void shifting(Array *arr,int shift, string type)
{
    if(type=="left")
    {   
        int i,j;
        for(i=0,j=shift;j<arr->length;i++,j++)
        {
            arr->a[i]=arr->a[j];
        }
        for(;i<arr->length;i++)arr->a[i]=0;
    }
    else
    {
        int i,j;
        for(i=arr->length-shift-1,j=arr->length-1;i>=0;i--,j--)arr->a[j]=arr->a[i];
        for(i=0;i<shift;i++)arr->a[i]=0;
    }
    
}

void _rotate(Array *arr,int rotate,string type)
{
    if(type=="left")
    {
       /* using jugling algorithm */
       /* using n = length of the array and k=shift value */
       /* number of sets(outer loop) will depend upon gcd of n,k */
        
        int temp,d=-1,j;
        int gcd=__gcd(arr->length,rotate);
        for(int i=0;i<gcd;i++)
        {
            j=i;
            temp=arr->a[i];
            while(1)
            {
                d=(j+rotate)%arr->length;
                if(d==i)break;
                arr->a[j]=arr->a[d];
                j=d;
            }
            arr->a[j]=temp;
        }
    }
    else if(type=="right")
    {
       _reverse(arr);
       _rotate(arr,rotate,"left");
       _reverse(arr);

    }
    else
    cout<<"Wrong input!";
}

void insert_in_sorted(Array *arr, int key)
{
    if(arr->length==arr->size)return;
    arr->a[arr->length]=key;
    int i=arr->length-1;
    while(1)
    {
        if(arr->a[i]>key)
        {
            swap(arr->a[i+1],arr->a[i]);
            i--;
        }
        else break;
    }
    arr->length++;
}

void Merge(Array *a1,Array *a2, int n1, int n2)
{
    int i,j,k;
    i=j=k=0;
    int merge_array[100]={0};
    while(i<n1 && j<n2)
    {
        if(a1->a[i]<a2->a[j])merge_array[k++]=a1->a[i++];
        else merge_array[k++]=a2->a[j++];
    }
    for(;i<n1;i++)merge_array[k++]=a1->a[i];
    for(;j<n2;j++)merge_array[k++]=a2->a[j];
    
    for(int l=0;l<n1+n2;l++)cout<<merge_array[l]<<" ";

    // time: O(m+n)
}

void Union(Array *a1,Array *a2, int n1, int n2)
{
    int i,j,k;
    i=j=k=0;
    int merge_array[100]={0};
    while(i<n1 && j<n2)
    {
        if(a1->a[i]<a2->a[j])merge_array[k++]=a1->a[i++];
        else if(a1->a[i]>a2->a[j])merge_array[k++]=a2->a[j++];
        else 
        {merge_array[k++]=a2->a[j];i++;j++;}
    }
    for(;i<n1;i++)merge_array[k++]=a1->a[i];
    for(;j<n2;j++)merge_array[k++]=a2->a[j];

    for(int l=0;l<n1+n2;l++)cout<<merge_array[l]<<" ";
}

void intersection(Array *a1,Array *a2, int n1, int n2)
{
    int i,j,k;
    i=j=k=0;
    int merge_array[100]={0};
    while(i<n1 && j<n2)
    {
        if(a1->a[i]<a2->a[j])merge_array[k++]=a1->a[i++];
        else if(a1->a[i]>a2->a[j])j++;
        else 
        {merge_array[k++]=a2->a[j];i++;j++;}
    }
    for(;i<n1;i++)merge_array[k++]=a1->a[i];
    for(int l=0;l<n1+n2;l++)cout<<merge_array[l]<<" ";
}

void Difference(Array *a1,Array *a2, int n1, int n2)
{
    int i,j,k;
    i=j=k=0;
    int merge_array[100]={0};
    while(i<n1 && j<n2)
    {
        if(a1->a[i]<a2->a[j])merge_array[k++]=a1->a[i++];
        else if(a1->a[i]>a2->a[j])j++;
        else 
        {i++;j++;}
    }
    for(int l=0;l<n1+n2;l++)cout<<merge_array[l]<<" ";

}

int main()
{
    Array array_1;
    Array array_2;
    create(&array_1,10);
    create(&array_2,10);
    insert_elements(&array_1,5);
    insert_elements(&array_2,5);
    Difference(&array_1,&array_2,5,5);
}