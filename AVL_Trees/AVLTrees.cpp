#include <iostream>  
 
using namespace std;
 
struct Node
{
    struct Node *lchild;
    int data;
    // for maintaining height 
    int height;
    struct Node *rchild; 
}*root=NULL;


int node_height(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}


int balance_factor(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}


Node* LLrotation(struct Node* p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=node_height(p);
    pl->height=node_height(pl);

    if(root==p)
    root=pl;

    return pl;  
}


Node* LRrotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=node_height(pl);
    p->height=node_height(p);
    plr->height=node_height(plr);

    if(p==root)root=plr;
    return plr;
}


Node* rInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        // assuming height starts from 1 and the height of the single leaf node will be 1
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=rInsert(p->lchild,key);

    }
     else if(key>p->data)
    {
        p->rchild=rInsert(p->rchild,key);
    }

    p->height=node_height(p);

    // checking balance factor for each node and performing rotation if required

    if(balance_factor(p)==2 && balance_factor(p->lchild)==1)
    {
        LLrotation(p);
    }

    return p;

}


int main()
{
    root=rInsert(root,10);
    rInsert(root,5);
    rInsert(root,2);

    cout<<root->data;
}