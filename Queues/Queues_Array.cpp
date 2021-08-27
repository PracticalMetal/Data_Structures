#include <iostream>  
 
using namespace std;
 
class Queues
{
    private:
    int size;
    int front,rear;
    int *Q;

    public:
    Queues(){size=10;front=rear=-1;Q=new int[size];}
    Queues(int size){this->size=size;front=rear=-1;Q-new int[size];}

    void enqueue(int x);   /* inserting element in the queue */
    int dequeue();        /* removing element in the queue */
    void display();/* for displaying */
    
};

void Queues::enqueue(int x)
{
    /* before inserting checking for overflow */
    if(rear==size-1)cout<<"Overflow \n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}

int Queues::dequeue()
{
    int x=-1;
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

int main()
{
    Queues abc(5);
    abc.enqueue(3);
    abc.enqueue(2);
    abc.display();
}