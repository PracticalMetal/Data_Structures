#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;

} *root = NULL;

Node *r_search(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    else if (key < p->data)
        return r_search(p->lchild, key);
    else
       return r_search(p->rchild, key);

    // return p;

    // TIME: O(logn)
}

Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;

    // TIME: O(logn)
}

void insert(struct Node *p, int key)
{
    /* checking if root=NULL */
    struct Node *t;
    if (root == NULL)
    {
        t = new Node;
        t->lchild = t->rchild = NULL;
        t->data = key;
        root = t;
    }
    else
    {
        struct Node *r = NULL; /* tailing pointer */
        while (t != NULL)
        {
            r = p;
            if (p->data = key)
                return;
            else if (key < p->data)
                p = p->lchild;
            else
                p = p->rchild;
        }
        t = new Node;
        t->data = key;
        if (key < r->data)
            r->lchild = t;
        else
            r->rchild = t;
    }

    // TIME: O(logn)
}

Node* r_insert(struct Node *p, int key)
{

    if (p == NULL)
    {
        struct Node *t;
        t = new Node;
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t;
    }
    else if (key < p->data)
        p->lchild = r_insert(p->lchild, key);
    else
        p->rchild = r_insert(p->rchild, key);

    return p;
}

void display(struct Node *p)
{
    if (p)
    {
        display(p->lchild);
        cout << p->data << " ";
        display(p->rchild);
    }
    return;
}

int height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    else
    {
        x = height(p->lchild);
        y = height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }
}

Node *inpre(struct Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *insucc(struct Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node *del(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;                            // if not found do nothing
    if(p->lchild == NULL && p->rchild == NULL && p->data==key) // if leaf node
    {
        if (p == root)
            root = NULL;
        delete (p);
        return NULL;
    }

    if (key < p->data)
        p->lchild=del(p->lchild, key);
    else if (key > p->data)
        p->rchild=del(p->rchild, key);
    else
    { // here the key to be deleted is found
        struct Node *q;
        if (height(p->lchild) > height(p->rchild))
        {
            // finding inorder pre
            q = inpre(p->lchild);
            // replacing the elements
            p->data = q->data;
            // checking for children of the inpre
            p->lchild = del(p->lchild, q->data);
        }
        else
        {
            q = insucc(p->rchild);
            p->data = q->data;
            p->rchild = del(p->rchild, q->data);
        }
        
    }
    return p;
}

void create_from_preorder(int preorder[], int n)
{
    int i=0;
    root=new Node;
    root->data=preorder[i++];
    root->lchild=root->rchild=NULL;

    struct Node *p,*t;
    p=root;

    stack<Node*> st;

    while(i<n)
    {
        if(preorder[i]<p->data)
        {
            t=new Node;
            t->lchild=t->rchild=NULL;
            t->data=preorder[i++];
            st.push(p);
            p->lchild=t;
            p=t;
        }
        else 
        {
            // checking if the the value lies between the  stack top and the current node
            if(preorder[i]>p->data && preorder[i]<(st.empty()?32767:st.top()->data))
            {
                t=new Node;
                t->lchild=t->rchild=NULL;
                t->data=preorder[i++];
                p->rchild=t;
                p=t;
            }
            else
            {
                p=st.top();
                st.pop();
            }
        }
    }
}

int main()
{
    int pre[]={30,20,10,15,25,40,50,45};
    int n=8;

    create_from_preorder(pre,n);
    display(root);

    // root=r_insert(root, 5);
    // r_insert(root, 6);
    // r_insert(root, 16);
    // r_insert(root, 62);
    // r_insert(root, 2);
    // r_insert(root, 26);
    
    // display(root);
 
    // del(root,166);
    // cout<<endl;
 
    // display(root);
}