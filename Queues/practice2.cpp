/* Implementing circular queue */
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
    int i=(q.front+1)%q.size;
    for(;i<=(q.rear)%q.size;i=(i+1)%q.size)cout<<q.Q[i]<<" "<<endl;
}

void enqueue(struct Queue *q, int x)
{
    // checking for overflow
    if((q->rear+1)%q->size==q->front)cout<<"Overflow! \n";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

void dequeue(struct Queue *q)
{
    // checking for underflow
    if(q->rear==q->front)cout<<"Underflow \n";
    else
    {
        q->front=(q->front+1)%q->size;
    }
}

int main()
{
    struct Queue q;
    q.size=5;
    q.front=q.rear=0; // for circular queue front and rear are initialized at 0
    q.Q=new int[q.size];

    enqueue(&q,1);
    enqueue(&q,2);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);


}