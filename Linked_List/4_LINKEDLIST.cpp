#include <bits/stdc++.h>  

using namespace std;
 
struct node 
{
    int data;
    struct node *next;
}*first=NULL;

//Creating a node
void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=new node;

    first->data=A[0];
    first->next=0;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        
        last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->next;
    }
}

void recursiveDisplay(struct node *p)
{
    if(p!=NULL)
    {
        recursiveDisplay(p->next);
        cout<<p->data<<"\t";
        
    }
}

int countNoOfElements(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int recursiveCount(struct node *p)
{
    if(p==0)
    return 0;
    else
    return 1+recursiveCount(p->next);

}

int Sum(struct node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int recursiveSum(struct node *p)
{
    if(p==NULL)
    return 0;
    
    return recursiveSum(p->next)+p->data; 
}

int Maxim(struct node *p)
{
    int Max=p->data;
    p=p->next;
    while(p)
    {
        if(p->data>Max)
        Max=p->data;

        p=p->next;
    }
    return Max;
}

int recursiveMaxim(struct node *p)
{
    int x=0;
    if(p==NULL)
    return INT_MIN;
    x=recursiveMaxim(p->next);
    return x>p->data?x:p->data;
}

node* Search(struct node *p,int key)
{
    while(p)
    {
        if(p->data==key)
        return p;
        else
        {p=p->next;} 
    }
    return NULL;
}

node* RSearch(struct node *p,int key)
{
    if(!p)
    return NULL;
    if(key==p->data)
    return p;
    else  
    return RSearch(p->next,key);
}

node* moveToHeadSearch(struct node *p,int key)
{
    node *q=NULL;
    while(p)
    {
        if(key==p->data)
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

void Insert(struct node *p,int value,int pos)
{
    node *t,*q;
    
    if(pos==0)
    {
        t=new node;
        t->data=value;
        t->next=first;
        first=t;
    }
    else
    {
        q=first;
        for(int i=0;i<pos-1 && q;i++)
        {
            q=q->next;
        }
        if(q)
        {
            t=new node;
            t->data=value;
            t->next=q->next;
            q->next=t;
        }
    }
}

// void insertAtLast(struct node *p,int x)
// {
//     node *t=new node;
//     t->data=x;
//     t->next=NULL;
//     node *last;
//     if(p==NULL)
//     {
//         p=last=t;
        
//     }
//     // Traversing to find last element
//     else
//     {
//         while(p)
//         {
//             last=p->next;
//         }
//         last->next=t;
        
//         last=t;

//     }
// }

void insertInSorted(struct node *p, int x)
{
    node *q=NULL,*t=new node;
    t->data=x;
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {t->next=p;
        first=t;}
        else
        {
            t->next=p;
            q->next=t;

        }
    }

}

void Delete(struct node* p,int pos)
{
    node *q=NULL;
    if(pos==1)
    {
        first=first->next;
        delete p;
    }
    else
    {
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }
}

bool ifSorted(struct node *p)
{
    if(count)
    node *q=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        if((q->data) > (p->data))
        return false;
    }
    return true;
}

int main()
{
    int A[]={1,2,3,14,15,16};
    create(A,6);

    cout<<ifSorted(first);    
    // display(first);
    
}   