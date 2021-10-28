#ifndef Chains_h
#define Chains_h

#include <iostream>

struct Node
{
    int data;
    struct Node *next;
}*root=NULL;

void sorted_insert(struct Node **H, int x)
{
    struct Node *t,*q=NULL,*p=*H;

    t=new Node;
    t->data=x;
    t->next=NULL;

    if(*H=NULL)
    {
        *H=t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==root)
        {
            t->next=root;
            root=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

#endif