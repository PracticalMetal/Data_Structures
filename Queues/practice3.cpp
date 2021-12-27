// Implementing queue using linked list

#include <iostream>  
 
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(struct Node *p, int x)
{
    // checking for overflow
    struct Node *t;
    t=new Node;
    if(t==NULL)cout<<"Overflow!\n";
    else
    {
        // checking if this node is the first node that is created
        if(front==NULL)
        {
            front=rear=t;
            t->data=x;
            t->next=NULL;
        }
        else
        {
            rear->next=t;
            t->next=NULL;
            t->data=x;
            rear=t;
        }
    }
}
 
void dequeue(struct Node *p)
{
    // checking for underflow
    if(front==NULL)cout<<"Underflow!\n";
    else
    {
        struct Node *d;
        d=front;
        front=front->next;
        delete(d);
    }
}


int main()
{
    
}