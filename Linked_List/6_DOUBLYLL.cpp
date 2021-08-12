#include <iostream>  
 
using namespace std;
 
struct node
{   
    node *prev;
    int data;
    node *next;
}*first=NULL;

void _create(int A[],int n)
{
    node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        t->prev=last;
        last=t;

    }

}

void display(node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void _insert(node *p, int data, int pos=0)
{
    node *t;
    t=new node;
    t->data=data;
    /* there will be two cases 
    1) inserting before 1st node
    2) inserting at the given position
    */

    if(first==NULL)
    {
        first=t;
        t->prev=t->next=NULL;
    } 
    else
    {
        if(pos==0)
        {
            t->next=first;
            t->prev=NULL;
            first->prev=t;
            first=t;
        }
        else
        {
            for(int i=0;i<pos-1;i++)p=p->next;
            t->next=p->next;
            p->next=t;
            if(t->next)             /* to check if there is a node available without this there will be segmetation error */
            t->next->prev=t;
            t->prev=p;

        }
    }
}

void _delete(node *p,int pos=1)
{
    if(first==NULL)return;
    else
    {
        if(pos==1)
        {
            first=first->next;
            delete first->prev;
        }
        else
        {
            node *q;
            for(int i=0;i<pos-2;i++)
            p=p->next;
            q=p->next;    /* on the node to be deleted */
            p->next=q->next;
            if(q->next)
            q->next->prev=p;
            delete q;
        }
    }

}

void reverse(node *p)
{
    while(p)
    {
        node *temp;
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;   /* because the nodes have been swapped therefore to traverse forward we use previous */
        
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    _create(A,5); 

    _delete(first,5);

    display(first);  
}