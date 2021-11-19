#include <iostream>  
 
using namespace std;
 
template<class T>
struct Node
{
    Node *prev;
    T data;
    Node *next;
};

struct Node<int> *first;

template<class T>
void create(T A[], int n)
{
    struct Node<T> *last,*t;
    first=new Node<T>;
    first->data=A[0];
    first->prev=first;
    first->next=first;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node<T>;
        t->data=A[i];
        t->next=first;
        t->prev=last;
        last->next=t;
        last=t;
        first->prev=last;
    }
}

template<class T>
void display(struct Node<T> *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=first);
}

template<class T>
void insert(struct Node<T> *p, int data, int pos)
{
    struct Node<T> *t;
    t=new Node<T>;
    t->data=data;    
    if(pos==1)
    {
        t->next=first;
        t->prev=first->prev;
        first->prev->next=t;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        p=p->next;
            t->next=p->next;
            t->prev=p;
            struct Node<T> *q=t->next;
            q->prev=t;
            p->next=t;
        
    }
}

template<class T>
void del(struct Node<T> *p, int pos)
{
    if(pos==1)
    {
        struct Node<T> *q=first;
        first=first->next;
        first->prev=q->prev;
        q->prev->next=first;
    }
    else
    {
        for(int i=0;i<pos-2;i++)p=p->next;
        p->next=p->next->next;
        p->next->prev=p;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    int n=5;
    create(A,n);

    del(first,4);
    display(first);
}