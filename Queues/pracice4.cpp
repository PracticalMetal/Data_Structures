/* Implementing DEQueue */

#include <iostream>  
 
using namespace std;
 
struct DEQueue
{
    int size;
    int front,rear;
    int *Q;
};

void insert_front(struct DEQueue *q,int x)
{
    if(q->front-1==-1)cout<<"Cannot insert from front!\n";
    else
    {
        q->front--;
        q->Q[q->front]=x;
    }

}

void insert_back(struct DEQueue *q,int x)
{
    if(q->rear==q->rear-1)cout<<"Cannot insert from back!\n";
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }

}

void delete_front(struct DEQueue *q)
{
    if(q->front==q->rear)cout<<"Cannot delete\n";
    else
    {
        q->front++;
    }
}


int main()
{
    struct DEQueue q;
    q.size=5;
    q.front=q.rear=-1;
    q.Q=new int[q.size];


}