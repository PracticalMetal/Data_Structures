#include <bits/stdc++.h>  
#include "Stacks.h"
 
using namespace std;
 
void insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;  // here r is tailing pointer and p is to create a new node

    if(root==NULL)
    {
        /* this means that this is the first node */
        /* creating a new node using p */
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return ;
    }
    while(t!=NULL)
    {
        r=t;
        if(t->data<key)t=t->rchild;
        else if(t->data>key)t=t->lchild;
        else return;
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(r->data<key)r->rchild=p;
    else r->lchild=p;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

Node* search(struct Node *p,int key)
{
    if(root==NULL)return NULL;
    while(p!=NULL)
    {
        if(p->data<key)p=p->rchild;
        else if(p->data>key)p=p->lchild;
        else return p;
    }
    return NULL;

}

Node* rInsert(struct Node *p, int key)
{
    if(p==NULL)
    {
        struct Node *t=new Node;
        t->rchild=t->lchild=NULL;
        t->data=key;
        return t;
    }
    if(key<p->data)p->lchild=rInsert(p->lchild,key);
    else if(key>p->data)p->rchild=rInsert(p->rchild,key);
    return p;

}

int height(struct Node *p)
{
    if(p==NULL)return 0;
    int x,y;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node* inpre(struct Node* p)
{
    while(p && p->rchild!=NULL)p=p->rchild;
    return p;
}

struct Node* insuc(struct Node* p)
{
    while(p && p->lchild!=NULL)p=p->lchild;
    return p;
}


struct Node* Delete(struct Node *p, int key)
{
    struct Node *q;
    if(p==NULL)return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)root=NULL;
        free(p);
        return NULL;    
    }
    if(key<p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=insuc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

void create_pre(int pre[],int n)
{
    Stack st;
    Node *t,*p;
    int i=0;

    root=new Node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new Node;
            t->data=pre[i++];
            t->rchild=t->lchild=NULL;
            p->lchild=t;
            _push_back(&st,p);
            p=t;
        }
        else
        {
            int upper_value;
            if(is_empty_stack(st))upper_value=INT_MAX;
            else upper_value=stack_top(st)->data;
            if(pre[i]>p->data && pre[i]<upper_value)
            {
                t=new Node;
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else
            {
                p=_pop(&st);
            }
        }
    }
    // time : O(n)
}

int main()
{
    insert(10);
    insert(5);
    insert(20);
    rInsert(root,8);
    insert(30);
    inorder(root);cout<<"\n";
    Delete(root,10);
    inorder(root);
}