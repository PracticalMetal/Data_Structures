#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void bubble_sort(int arr[], int n)
{
    // to make the algo adaptive, ie it will take minimum time if already sorted
    int flag;

    // first loop is for passes
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        // second loop is for comparisons
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag++;
                swap(arr[j + 1], arr[j]);
            }
        }
        if (flag == 0)
            break;
    }
    // TIME : min- O(n)  max- O(n^2)
    // ADAPTIVE : yes
    // STABLE : yes
    // first k iterations give k max elements
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j, x;
        j = i - 1;
        x = arr[i];
        while (arr[j] > x && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }

    // time : min- O(n)   max-O(n^2)
    // adaptive: yes(through its own algo)
    // stable : yes
    // first k interations wont give any useful result
    // only bubble and insertion sort are adaptive
}

void selection_sort(int arr[], int n)
{
    // first pass is for selection the element to be swapped with the smallest element
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        // second loop is for finding the smallest element
        for (j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
    // TIME : O(n^2)
    // Utilizes minimum swap O(n)
    // ADAPTIVE : No
    // STABLE : No
}

int partition(int arr[], int l, int h)
{
    int i, j, pivot;

    pivot = arr[l];
    i = l;
    j = h;

    do
    {
        do
        {
            i++;
        } while (!(arr[i] > pivot));
        do
        {
            j--;
        } while (!(arr[j] <= pivot));
        if (i < j)
            swap(arr[i], arr[j]);

    } while (i < j);
    swap(arr[l], arr[j]);

    return j;
}

void quick_sort(int arr[], int l, int h)
{
    int j;
    // condition to check that there are more than 2 elements
    if (l < h)
    {
        j = partition(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, h);
    }
}

// void merge(int arr[], int l, int mid, int h)
// {
//     int i,j,k;
//     i=l;
//     j=mid+1;
//     k=l;

//     // auxilary array for storing the sorted elements
//     int brr[h+1];

//     while(i<=mid && j<=h)
//     {
//         if(arr[i]<arr[j])
//         brr[k++]=arr[i++];

//         else
//         brr[k++]=arr[j++];
//     }

//     // copying the rest of the elements
//     for(;i<=mid;i++)brr[k++]=arr[i];
//     for(;j<=h;j++)brr[k++]=arr[j];

//     // copying back the elements to arr
//     for(int i=l;i<=h;i++)arr[i]=brr[i];

//     // TIME : O(m+n)
// }

// void merge_sort(int arr[], int n)
// {
//     int p; // for passes
//     int l,h,mid,i;
//     for(p=2;p<=n;p=p*2)
//     {
//         for(i=0;i+p-1<n;i=i+p)
//         {
//             l=i;
//             h=i+p-1;
//             mid=(l+h)/2;

//             merge(arr,l,mid,h);
//         }
//         if(n-i>p/2)
//         {
//         l = i;
//         h = i+p-1;
//         mid = (l+h)/2;
//         merge(arr, l, mid, n-1);
//         }

//     }
//     if(p/2<n)
//     merge(arr,0,p/2-1,n-1);
// }

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void merge_sort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

void r_merge_sort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid;
        mid=(l+h)/2;
        r_merge_sort(arr,l,mid);
        r_merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}


void count_sort(int arr[], int n)
{
    int m=*max_element(arr,arr+n);

    int H[m+1]; // initial array
    for(int i=0;i<m+1;i++)H[i]=0;

    for(int i=0;i<n;i++)H[arr[i]++];

    int i=0;
    int k=0;
    while(i<m+1)
    {
        if(H[i]>0)
        {
            arr[k++]=i;
            H[i]--;
        }
        else
        {
            i++;
        }
    }
}

// void radix_sort(int arr[], int n)
// {
//     // finding the maximum element to get the number of degits
//     int m = *max_element(arr, arr + n);
//     int temp = m;
//     int dig = 0;
//     int divisor = 1;

//     while (temp)
//     {
//         dig++;
//         temp /= 10;
//     }

//     // defining bins
//     vector<Node *> BIN(10, NULL);

//     while (dig--)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             int index = (arr[i] / divisor) % 10;
//             Node *t;
//             t = new Node;
//             t->data = arr[i];
//             t->next = NULL;

//             // Node *p;
//             // p = BIN[index];
//             while (BIN[index] && BIN[index]->next != NULL)
//                 BIN[index] = BIN[index]->next;
//             if(BIN[index])
//             BIN[index]->next = t;
//         }
//         divisor*=10;
//         int k=0;
//         for(int i=0;i<10;i++)
//         {
//             // Node *p=BIN[i];
//             while(BIN[i])
//             {
//                 arr[k++]=BIN[i]->data;
//                 BIN[i]=BIN[i]->next;
//             }
//         }
//     }
// }

void radix_sort(int arr[], int n)
{
    // finding the maximum element to get the number of degits
    int m = *max_element(arr, arr + n);
    int temp = m;
    int dig = 0;
    int divisor = 1;
 
    while (temp)
    {
        dig++;
        temp /= 10;
    }
 
    // defining bins
    vector<Node *> BIN(10, NULL);
 
    while (dig--)
    {
        for (int i = 0; i < n; i++)
        {
            int index = (arr[i] / divisor) % 10;
            Node *t;
            t = new Node;
            t->data = arr[i];
            t->next = NULL;
 
            Node *p;
            p = BIN[index];
            
            if(!p){// if nothing is present
                BIN[index]=t;
            }else{
            
            while (p && p->next != NULL) //changes
                p= p->next; //changes
            p->next=t; 
            }
        }
        divisor*=10;
        int k=0;
        for(int i=0;i<10;i++)
        {
            // Node *p=BIN[i];
            while(BIN[i])
            {
                arr[k++]=BIN[i]->data;
                BIN[i]=BIN[i]->next;
            }
        }
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 21}, n = 11;
    radix_sort(A, n);
    for (int x : A)
        cout << x << " ";
}