#include <iostream>  
 
using namespace std;
 
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
    int height;
}*root=NULL;

int node_height(struct Node *p)
{
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int balance_factor(struct Node *p)
{
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;

    return hl-hr;
}

Node* ll_rotation(struct Node *p)
{
    struct Node *pl,*plr;
    pl=p->lchild;
    plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=node_height(p);
    pl->height=node_height(pl);

    if(p==root)root=pl;
    return pl;
}

Node* rr_rotaion(struct Node *p)
{
    struct Node *pr,*prl;

    pr=p->rchild;
    prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=node_height(p);
    pr->height=node_height(pr);

    if(p==root)root=pr;

    return pr;
}

Node* lr_rotation(struct Node *p)
{
    struct Node *pl,*plr;
    pl=p->lchild;
    plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    plr->height=node_height(plr);
    pl->height=node_height(pl);
    p->height=node_height(p);

    if(p==root)root=plr;
    return plr;

}

Node* rl_rotation(struct Node *p)
{
    struct Node *pr,*prl;
    pr=p->rchild;
    prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    prl->height=node_height(prl);
    pr->height=node_height(pr);
    p->height=node_height(p);

    if(p==root)root=prl;
    return prl;

}

Node* r_insert(struct Node *p, int key)
{
    if(p==NULL)
    {
        struct Node *t;
        t=new Node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(key<p->data)p->lchild=r_insert(p->lchild,key);
    else if(key>p->data)p->rchild=r_insert(p->rchild,key);

    p->height=node_height(p);

    if(balance_factor(p)==2 && balance_factor(p->lchild)==1)
    {
        ll_rotation(p);
    }
    else if(balance_factor(p)==2 && balance_factor(p->lchild)==-1)
    {
        lr_rotation(p);
    }
    else if(balance_factor(p)==-2 && balance_factor(p->lchild)==-1)
    {
        rr_rotaion(p);
    }
    else if(balance_factor(p)==-2 && balance_factor(p->lchild)==1)
    {
        // rl_rotation(p);
    }

    return p;
}

int main()
{
    root=r_insert(root,30);
    r_insert(root,20);
    r_insert(root,10);

    cout<<root->lchild<<" "<<root->rchild;
}