/* Implementing trees */

#include <iostream>  
#include <queue> 

using namespace std;
 
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void create()
{
    struct Node *p,*t;
    int x;
    queue<Node*> q;
    cout<<"Enter root value: \n";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.push(root);

    while(!q.empty())
    {
        p=q.front();
        q.pop();
        int l,r;
        cout<<"Enter left child, if none, enter -1: \n";
        cin>>l;
        if(l!=-1)
        {
            t=new Node;
            t->lchild=t->rchild=NULL;
            t->data=l;
            p->lchild=t;
            q.push(t);
        }
        cout<<"Enter right child, if none, enter -1: \n";
        cin>>r;
        if(r!=-1)
        {
            t=new Node;
            t->lchild=t->rchild=NULL;
            t->data=r;
            p->rchild=t;
            q.push(t);
        }
    }
}

void r_preorder(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        r_preorder(p->lchild);
        r_preorder(p->rchild);
    }
    // time: O(2n+1)
    // space: O(h)
}

void r_inorder(struct Node *p)
{
    if(p)
    {
        r_preorder(p->lchild);
        cout<<p->data<<" ";
        r_preorder(p->rchild);
    }
    // time: O(2n+1)
    // space: O(h)
}

void r_postorder(struct Node *p)
{
    if(p)
    {
        r_preorder(p->lchild);
        r_preorder(p->rchild);
        cout<<p->data<<" ";
    }
    // time: O(2n+1)
    // space: O(h)
}


int main()
{
    create();
    r_inorder(root);
}