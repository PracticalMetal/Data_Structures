#include <iostream>
#include "Queue.h"
#include "Stacks.h"

struct Node *root=NULL;

void tree_create ()
{
    Node *p,*t;  /* p is for linking and t is for making new nodes */
    int x;
    Queues q;
    cout<<"Enter root value: ";
    cin>>x;
    root= new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;

    q.enqueue(root);     // sending address values to the queue
    while(!isEmpty(q))
    {
        p=q.dequeue();
        cout<<"Enter Lchild of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=0;
            p->lchild=t;
            q.enqueue(t);
        }

        cout<<"Enter Rchild of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=0;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        
        inorder(p->lchild);cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        
        postorder(p->lchild);
        postorder(p->rchild);cout<<p->data<<" ";
    }
}

int main()
{
    tree_create();
    preorder(root);   
}