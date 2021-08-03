#include <bits/stdc++.h>  
 
using namespace std;
using namespace std::chrono;

struct node
{
    int data;
    node *next;
}*first=NULL;

void Create(int A[],int n)
{
    node *t,*last;
    t=new node;
    t->data=A[0];
    t->next=NULL;
    first=t;
    for(int i=1;i<n;i++)
    {
        last=new node;
        last->data=A[i];
        t->next=last;
        t=last;
    }

    
}

void Display(node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void rDisplay(node *p)
{
    if(p)
    {cout<<p->data<<" ";
    rDisplay(p->next);}
}

int Count(node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

int rCount(node *p)
{
    if(!p)
    return 0;
    else
    return 1+rCount(p->next);
}

int Sum(node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;

}

int rSum(node *p)
{
    if(!p)return 0;
    return p->data+rSum(p->next);
}

int Maxim(node *p)
{
    int Max=first->data;
    p=p->next;
    for(int i=1;i<Count(first);i++)
    {
        if(p->data>Max)Max=p->data;
        p=p->next;
    }
    return Max;
}

int rMaxim(node *p)
{
    if(!p)return INT_MIN;
    int x=p->data;
    return x>rMaxim(p->next)?x:rMaxim(p->next);
}

node* Search(node *p,int key)
{
    while(p)
    {
        if(p->data==key)
        return p;
        p=p->next;
    }
    return NULL;
}

node* rSearch(node *p,int key)
{
    if(!p)return NULL;
    if(p->data==key)return p;
    else return rSearch(p->next,key);
}

node* improveSearch(node *p,int key)
{
    node *q=NULL;
    while(p)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;
    }
    return NULL;

}

void Insert(node *p,int x,int pos=1)
{
    node *q=NULL,*t;
    t=new node;
    t->data=x;

    if(pos==1)
    {
        if(first==NULL)
        {
            first=new node;
            first->data=x;
            first->next=NULL;
        }
        else
        {
            
            t->next=first;
            first=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=t;
        t->next=p;
    }
}

void Pop_back(node *p, int data)
{
    node *t,*q=NULL;
    t=new node;
    t->data=data;
    t->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
    }
    q->next=t; 
}

void insertInSorted(node *p,int data)
{
    node *q=NULL;
    node *t=new node;
    t->data=data;

    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<data)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=p;
            first=t;
        }
        q->next=t;
        t->next=p;
    }
}

int main()
{
    int arr[]={1,2,3,4,5,66,77};
    Create(arr,7);

   insertInSorted(first,-78);
   Display(first);

    
}