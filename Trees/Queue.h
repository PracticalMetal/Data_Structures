#ifndef Queue_h
#define Queue_h

#include <iostream>  
 
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
 
class Queues
{
    public:
    int size;
    int front,rear;
    Node **Q;

    public:
    Queues(){size=10;front=rear=-1;Q=new Node*[size];}
    Queues(int size){this->size=size;front=rear=-1;Q=new Node*[size];}

    void enqueue(Node* x);   /* inserting element in the queue */
    Node* dequeue();        /* removing element in the queue */
    void display();/* for displaying */
    
};

void Queues::enqueue(Node* x)
{
    /* before inserting checking for overflow */
    if(rear==size-1)cout<<"Overflow \n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node* Queues::dequeue()
{
    Node* x=NULL;
    if(front==rear)cout<<"Underflow \n";
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

void Queues::display()
{
    for(int i=front+1;i<=rear;i++)cout<<Q[i]<<" ";
}

bool isEmpty(Queues q)
{
    return q.front==q.rear;
}

#endif /* Queue_h */