#include <iostream>  
 
using namespace std;
 
struct Queue
{
    int size;
    int front,rear;
    int *Q;
};

void display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)cout<<q.Q[i]<<" ";
}

void enqueue(struct Queue *q, int x)
{
    // checking for overflow
    if(q->rear==q->size-1)
    {
        cout<<"Overflow! \n";
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    // checking for underflow
    int x=-1;
    if(q->front==q->rear==-1)cout<<"Underflow\n";
    else
    {
        
        x=q->Q[q->front];
        q->front++;
    }
    return x;
}


int main()
{
    struct Queue q;
    cout<<"Enter the size of the queue \n";
    cin>>q.size;
    q.front=q.rear=-1;
    q.Q=new int[q.size];

    enqueue(&q,4);
    enqueue(&q,5);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);


}