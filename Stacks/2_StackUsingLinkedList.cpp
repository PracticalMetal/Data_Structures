#include <iostream>  
 
using namespace std;
 
struct node
{
    int data;
    node *next;
}*top=NULL;

void display(struct node *p)
{
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
}

void _push_back(int x)
{   
    node *t;
        t=new node;
    /* checking for overflow condition */
    if(t==NULL)return;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

void _pop(struct node *p)
{
    if(top==NULL)return;
    else
    {
        node *p=top;
        top=top->next;
        delete(p);
    }
}

int peek(struct node *p, int pos)
{
    if(top==NULL)return -1;
    else
    {
        for(int i=0;i<pos-1 && p;i++)p=p->next;
        return p->data;
    }
}

int stack_top(struct node *p)
{
    if(top)return top->data;
    else return -1;
}

bool is_empty(struct node *p)
{
    return top==NULL?true:false;
}

bool is_full(struct node *p)
{
    node *t=new node;
    bool c=t?true:false;
    delete (t);
    return c;
}

int main()
{
    // struct node *p=top;
    _push_back(10);
    
    display(top);
    cout<<"\n";
    _pop(top);
    display(top);

}