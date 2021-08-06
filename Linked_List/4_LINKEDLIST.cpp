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
    node *q=NULL;
    if(first==NULL || countNoOfElements(p)==1)return true;
    else
    {
        for(int i=0;i<countNoOfElements(first)-1;i++)
        {
            q=p;
            p=p->next;
            if(q->data>p->data)return false;
        }
        return true;
    }
}

void removeDuplicates()
{
    node *q=first,*p=first->next;
    while(p)
    {
        if(p->data!=q->data)
        {
            q=p;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            delete p;
            p=q->next;
        }
    }
}

void recursiveRemoveDuplicates(node *p)
{
    
    node *to_free;

    if(first==NULL)return;
    
    if(p!=NULL)
    {
        if(p->data==p->next->data)
        {
            to_free=p->next;
            p->next=p->next->next;
            free(to_free);
            recursiveRemoveDuplicates(p);
        }
        else
        {
            recursiveRemoveDuplicates(p->next);
        }
    }
    
}

void reversingUsingArray(struct node *p)
{   int i=0;
    int arr[countNoOfElements(first)];
    while(p)
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }
    i--;p=first;
    while(p)
    {
        p->data=arr[i--];
        p=p->next;
    }

    // time     :   O(2n)=O(n)
    // space    :   O(2n)=O(n)
}

void reversingUsingSlidingPointers(struct node *p)
{
    node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

    // time     :   O(n)
    // space    :   O(1)
}

void reversingUsingRecursion(struct node *q,struct node *p)
{  
    if(p!=NULL)
    {
        reversingUsingRecursion(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

int main()
{
    int A[]={1,2,3,4,5,6};
    create(A,6);

    node *p=first,*q=NULL;
    reversingUsingRecursion(q,p);    
    display(first);
    
}   