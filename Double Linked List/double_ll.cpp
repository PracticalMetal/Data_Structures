#include <iostream>

using namespace std;

template <class T>
struct Node
{
    /* structure for double ended linked list */
    Node *prev;
    T data;
    Node *next;
};

struct Node<int> *first;

template <class T>
void create(T A[], int n)
{
    Node<T> *last, *t;
    /* assigning first to a new node */
    if (n <= 0)
        return;
    first = new Node<T>;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    /* inserting the rest of the elements */
    for (int i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

template <class T>
void display(struct Node<T> *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

template <class T>
void insert(struct Node<T> *p, T data, int pos)
{
    /* two cases for inserting in a double LL */
    /* 1) inserting before the first element, 
    2) inserting before a given position */

    struct Node<T> *t;
    t = new Node<T>;
    t->data = data;
    t->next = t->prev = NULL;

    // inserting before the first element
    if (pos == 1)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
            p = p->next;

        t->next = p->next;
        struct Node<T> *q = p->next;
        if (q)
        {
            q->prev = t;
        }
        t->prev = p;
        p->next = t;
    }
}

template <class T>
void del(struct Node<T> *p, int pos)
{
    /* two cases while deleting:
    1) Deleting the first Node
    2) Deleting the given position */
    if (first == NULL)
        return;
    if (pos == 1)
    {
        struct Node<T> *q = first;
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        delete (q);
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        struct Node<T> *q = p->next->next;
        ;
        if (q)
        {
            q->prev = p;
        }
        if (p->next->next)
            p->next = q;
        else
            p->next = NULL;
    }
}
template<class T> 
void reverse(struct Node<T> *p)
{
    /* reversing the links */
    while(p)
    {
        auto temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        if(p->prev==NULL)first=p;
        p=p->prev;
        
        
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    create(A, n);

    reverse(first);
    display(first);
}