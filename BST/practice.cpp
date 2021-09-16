#include <iostream>  
#include "Stacks.h" 


using namespace std;


void insert(int key)
{
    struct Node *p=root,*r,*t;
    if(root==NULL)
    {
        root= new Node;
        root->lchild=root->rchild=NULL;
        root->data=key;
        return ;
    }
    while(p!=NULL)
    {
        r=p;
        if(p->data>key)
        {
            p=p->lchild;
        }
        else if(p->data<key)
        {
            p=p->rchild;
        }
        else return ;
    }
    t=new Node;
    t->data=key;
    t->rchild=t->lchild=NULL;
    if(r->data>key)
    {
        r->lchild=t;
    }
    else r->rchild=t;

    // time: O(logn)
}

Node* rInsert(struct Node *p,int key)
{
    // struct Node *p=root;
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=new Node;
        t->lchild=t->rchild=NULL;
        t->data=key;
        
    }
    else if(p->data>key)p->lchild=rInsert(p->lchild,key);
    else if(p->data<key)p->rchild=rInsert(p->rchild,key);
    return t;
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

int height(struct Node *p)
{
    if(p==NULL)return 0;
    int x,y;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

Node* inpre(struct Node *p)
{
    while(p && p->rchild)p=p->rchild;
    return p;
}

Node* insucc(struct Node *p)
{
    while(p && p->lchild)p=p->lchild;
    return p;
}

Node* Delete(struct Node *p, int key)
{
    struct Node *q=NULL;
    if(p==NULL)return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)root=NULL;
        free (p);
        return NULL;
    }
    else if(p->data>key)p->lchild=Delete(p->lchild,key);
    else if(p->data<key)p->rchild=Delete(p->rchild,key);
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
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

void create_pre(int pre[], int n)
{
    Stack st;
    create_stack(&st,100);
    Node *t,*p=root;
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
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            _push_back(&st,p);
            p=t;
        }
        else
        {
            if(pre[i]>p->data && (pre[i]<(is_empty_stack(st) ? 32767 : (stack_top(st))->data)))
            {
                t=new Node;
                t->rchild=t->lchild=NULL;
                t->data=pre[i++];
                p->rchild=t;
                p=t;
            }
            else
            {
                p=_pop(&st);
            }
        }

    }
}


 
int main()
{
    int arr[]={23,45,1,78,34};
    create_pre(arr,5);
    inorder(root);
}