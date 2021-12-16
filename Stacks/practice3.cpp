#include <iostream>  
 
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void push(int data)
{
    struct Node *t;
    t=new Node;
    t->data=data;
    t->next=top;
    top=t;

}

int pop()
{
    if(top==NULL)return -1;
    struct Node *p;
    p=top;
    int x=p->data;
    top=top->next;
    delete(p);
    return x;
}

int main()
{
    push(1);
    push(2);
    display(top);
    pop();
    display(top);    
}