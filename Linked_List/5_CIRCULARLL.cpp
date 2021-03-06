#include <iostream>  
 
using namespace std;

class node
{
    public:
    int data;
    node *next;
}*HEAD;

void create(int A[], int n)
{
    node *t, *last;
    HEAD=new node;

    HEAD->data=A[0];
    HEAD->next=HEAD;     /* circular linked list points to the start */

    last=HEAD;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=last->next;     /* will always point to HEAD */
        last->next=t;
        last=t;
    }

}



void display(struct node *p)
{
    do                          /* do while because initially p will be equal to HEAD */
    {   
        cout<<p->data<<" ";
        p=p->next;

    } while (p!=HEAD);
    
}

void rdisplay(struct node *p)
{
    static int flag=0;
    /* we use flag because initially p and HEAD are same therefore the if condition wont work */

    if(flag==0 || p!=HEAD)
    {   
        flag=1;
        cout<<p->data;
        rdisplay(p->next);
    }
    flag=0;
}

void _insert(struct node *p, int data, int pos=0)
{
    /* there are two condition where we can insert 
    1) before HEAD 
    2) given position 
    */
   node *t;
   t=new node;
   t->data=data;

   if(HEAD==NULL)
   {
       HEAD=t;
       HEAD->next=HEAD;
   }
   if(pos==0)
   {
       t->next=HEAD;
       node *p=HEAD;
       while(p->next!=HEAD)
       p=p->next;
       p->next=t;
   }
   else
   {    
       node *p=HEAD;
       for(int i=0;i<pos-1;i++)
       {
           p=p->next;
       }
       t->next=p->next;
       p->next=t;
   }
}

void _delete(node *p, int pos=1)
{
    /* there can again be two cases
    1) deleting and shifting the head
    2) deleting from a given position */

    if(HEAD==NULL)return; /* checking for empty list */
    if(pos==1)
    {
        while(p->next!=HEAD)p=p->next;
        if(p==HEAD)
        {
        free(HEAD);
        HEAD=NULL;
        }
        node *temp=HEAD;
        p->next=HEAD->next;
        HEAD=HEAD->next;
        free(temp);
    }
    else
    {
        for(int i=0;i<pos-2;i++)p=p->next;
        node *q=p->next;
        p->next=q->next;
        free(q);
    }

}

int main()
{
    int a[]={1,21,32,43,54};
    create(a,5);

    _delete(HEAD,8);

    display(HEAD);
}