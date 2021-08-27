#include <iostream>  
 
using namespace std;
 
// Cicular implementation

class Queue
{
    private:
    int size;
    int front,rear;
    int *Q;

    public:
    Queue(int size=10){this->size=size;front=rear=0;Q=new int[10];}
    void display();
    void enqueue(int x);    /* for inserting */
    int dequeue();         /* for deleting */

};

void Queue::display()
{
    int temp=front+1;
    do
    {
        cout<<Q[temp]<<" ";
        temp=(temp+1)%size;
    }while(temp!=(rear+1)%size);
}

void Queue::enqueue(int x)
{
    /* checking for overflow condition */
    if((rear+1)%size==front)
    {
        cout<<"Overflow \n";
        return;
    }
    /* move rear to the next position */
    rear=(rear+1)%size;
    Q[rear]=x;
}

int Queue::dequeue()
{   int x=-1;
    /* checking for underflow condition */
    if(rear==front)
    {
        cout<<"Underflow \n";
        return x;
    }
    /* moving front */
    
    front=(front+1)%size;
    x=Q[front];
    return x;    
}

int main()
{
    Queue q;
    q.enqueue(3);
    // q.enqueue(4);
    q.display();
    q.dequeue();
    q.display();   
}