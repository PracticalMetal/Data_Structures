#include <iostream>
#include "Queue.h"
#include "Stacks.h"

using namespace std;

struct Node *root = NULL;

void create_bt()
{
    Node *p,*t;
    /* p is for asking for lchild and rchild   &   t is for creating new node */
    int x;  // for storing value
    Queues q; // for storing addresses 

    cout<<"Enter the root value : \n";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;  // setting lchild and rchild initially as NULL

    q.enqueue(root);  // enqueuing in a queue 

    while(!isEmpty(q))
    {
        p=q.dequeue();
        cout<<"Enter left child : \n";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            q.enqueue(t);
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
        }
        cout<<"Enter right child : \n";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            q.enqueue(t);
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
        }
    }
}

void preorder_recursive(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder_recursive(p->lchild);
        preorder_recursive(p->rchild);
    }
}

void inorder_recursive(struct Node *p)
{
    if(p)
    {
        inorder_recursive(p->lchild);
        cout<<p->data<<" ";
        inorder_recursive(p->rchild);
    }
}

void postorder_recursive(struct Node *p)
{
    if(p)
    {
        postorder_recursive(p->lchild);
        postorder_recursive(p->rchild);
        cout<<p->data<<" ";
    }

    // time : O(2n+1)=O(n)        space : O(h) 
}

void preorder_iterative(struct Node *p)
{
    struct Stack st; // for storing addresses
    create(&st,100);
    while(p!=NULL || !is_empty_stack(st))
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            _push_back(&st,p);
            p=p->lchild;
        }
        else
        {
            p=_pop(&st);
            p=p->rchild;
        }
    }
}

void inorder_iterative(struct Node *p)
{
    struct Stack st;
    create(&st,100);
    while(p || !is_empty_stack(st))
    {
        if(p)
        {
            _push_back(&st,p);
            p=p->lchild;
        }
        else
        {
            p=_pop(&st);
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

void postorder_iterative(struct Node *p)
{
    struct Stack st;
    long int temp;
    create(&st,100);
    while(p || !is_empty_stack(st))
    {
        if(p)
        {
            _push_back(&st,p);
            p=p->lchild;
        }
        else
        {
            temp=(long int)_pop(&st);
            if(temp>0)
            {
                _push_back(&st,(Node*)-temp);
                p=((Node *)temp)->rchild;
            }
            else
            {
                cout<<((Node*)(-1 * temp))->data<<" ";
                p=NULL;

            }
        }
    }
}

void levelorder(struct Node *p)
{
    Queues q;
    cout<<p->data<<" ";
    q.enqueue(p);
    while(!isEmpty(q))
    {
        p=q.dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
}

int count(struct Node* p)
{
    int x,y;
    if(p)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;

}

int count_deg_two(struct Node *p)
{   
    int x,y;
    if(p)
    {
        x=count_deg_two(p->lchild);
        y=count_deg_two(p->rchild);
        if(p->rchild && p->lchild)return x+y+1;
        else return x+y;
    }
    return 0;
}

int height(struct Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)return x+1;
        else return y+1;
    }
    return 0;
}

int count_external_nodes(struct Node *p)
{
    int x,y;
    if(p)
    {
        x=count_external_nodes(p->lchild);
        y=count_external_nodes(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)return x+y+1;
        else return x+y;
    }
    return 0;
}

int main()
{
    create_bt();
    cout<<count_external_nodes(root);
}