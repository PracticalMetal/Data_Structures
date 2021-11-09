#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *next;
};
// declaring global variables
struct Node<int> *head = NULL;

template <class T>
void create(T A[], int n)
{
    struct Node<T> *t, *last; // to create a new node
    head = new Node<T>;
    head->data = A[0];
    head->next = head;
    last = head; /* last will always point to head */

    for (int i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = last->next; /* will always point to the head */
        last->next = t;
        last = t;
    }
}

template <class T>
void display(struct Node<T> *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

template <class T>
void r_display(struct Node<T> *p)
{
    static int flag = 0;
    if (flag == 0 || p != head)
    {
        flag = 1;
        cout << p->data << " ";
        r_display(p->next);
    }
}

template<class T>
void insert(struct Node<T> *p, T x, int pos=0)
{
    struct Node<T> *t;
    if(pos==0)
    {  
        if(head==NULL)
        {
            t=new Node<T>;
            t->next=t;
            t->data=x;
            head=t;
        }
        else
        {
            struct Node<T> *p=head;
            while(p->next!=head)p=p->next;
            t=new Node<T>;
            t->data=x;
            t->next=head;
            p->next=t;
            head=t;
        }
    }
    else
    {
        t=new Node<T>;
        t->data=x;
        struct Node<T> *p=head;
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

template<class T>
void del(struct Node<T> *p, int pos)
{
    /* identifying the last node */
    struct Node<T> *q=NULL;
    if(pos==0)
    {
        while(p->next!=head)p=p->next;
        q=head->next;
        p->next=q;
        head=q;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            q=p;
            p=p->next;
            
        }q->next=p->next;
            delete (p);
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int n = 5;
    create(A, n);
    insert(head,6,5);
    del(head,4);
    r_display(head);
}