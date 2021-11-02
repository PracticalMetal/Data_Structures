#include <iostream>
#include <climits>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
};
// defining a global variable first
Node<int> *first = NULL;

void create(int A[], int n)
{
    Node<int> *head;
    head = new Node<int>;
    head->data = A[0];
    head->next = NULL;

    Node<int> *last, *t;
    // last: to point to the last node
    // t: to create new node
    first = last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node<int>;
        t->next = NULL;
        t->data = A[i];
        last->next = t;
        last = last->next;
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
void r_display(struct Node<T> *p)
{
    if (p == NULL)
        return;
    cout << p->data << " ";
    r_display(p->next);
}

template <class T>
int nodes(struct Node<T> *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

template <class T>
int r_nodes(struct Node<T> *p)
{
    if (!p)
        return 0;
    return 1 + r_nodes(p->next);
}

template <class T>
T sum(struct Node<T> *p)
{
    T sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

template<class T>
T r_sum(struct Node<T> *p)
{
    if(!p)return 0;
    T x=p->data;
    return x+r_sum(p->next);
}

template<class T>
T maxim(struct Node<T> *p)
{
    T m;
    if(first==NULL)return -1;
    m=p->data;
    p=p->next;
    while(p)
    {
        if(p->data>m)m=p->data;
        p=p->next;
    }
    return m;
}

template<class T>
T r_maxim(struct Node<T> *p)
{
    T x;
    if(p==NULL)return INT_MIN;
    else
    {
        x=r_maxim(p->next);
        return x>p->data?x:p->data;
    }
}

template<class T>
Node<T>* search(struct Node<T> *p, T key)
{
    while(p)
    {
        if(p->data==key)return p;
        p=p->next;
    }
    return NULL;
}  

template<class T>
Node<T>* r_search(struct Node<T> *p, T key)
{
    if(!p)return NULL;
    return p->data==key?p:r_search(p->next,key);
}

template<class T>
Node<T>* improved_seach(struct Node<T> *p, T key)
{   
    // to check how many iterations the function took to find the element
    int no_of_iterations=0;
    // to check if linked list is empty
    if(first==NULL)return NULL;

    // trailing pointer to switch nodes
    struct Node<T> *q=NULL;
    while(p)
    {
        if(p->data==key)
        {
            if(q!=NULL)
            {q->next=p->next;
            p->next=first;
            first=p;}
            cout<<"No of iterations= "<<no_of_iterations<<"\n";
            return p;
        }
           
        no_of_iterations++;
        q=p;
        p=p->next;
        
    }
    return NULL;
}

template<class T>
Node<T>* insert(struct Node<T>* p, T data, int pos=0)
{
    /* there are two cases in this:
    1. Inserting before the first node
    2. Inserting after a given node */
    
    // checking if empty
    if(first==NULL)return NULL;
    // for creating a new node
    struct Node<T>* t;
    t=new Node<T>;
    t->next=NULL;
    t->data=data;

    // if pos==0
    if(pos==0)
    {
        t->next=first;
        first=t;
        return t;
    }
    // rest of the cases
    struct Node<T>* q=NULL; // trailing pointer to change links
    // using for loop to iterate to the given pos and changing links
    for(int i=0;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    // if p is NULL making new node's next as NULL and make q point to p, else q's next= t and t's next is p
    if(p==NULL)
    {
        q->next=t;        
    }
    else
    {
        q->next=t;
        t->next=p;
    }
    return t;

}

template<class T>
Node<T>* insert_in_sorted(struct Node<T>* p, T data)
{
    // creating a new node
    struct Node<T>* t;
    t=new Node<T>;
    t->data=data;
    t->next=NULL;

    // checking if linked list is empty
    if(first==NULL)
    {
        first=t;
        return t;
    }
    // checking if smaller than first node
    if(data<=p->data)
    {
        t->next=first;
        first=t;
        return t;
    }
    // checking if the next node is greater than the previous
    while(p->next)
    {
        if(p->next->data>data)break;
        p=p->next;
    }
    struct Node<T> *  q=p->next;
    p->next=t;
    t->next=q;
    return t;
}


template<class T>
void _delete(struct Node<T>* p, int pos)
{
    /* there are two cases:
    1. Deleting the first node
    2. Deleting the node at given position */
    // Deleting the first node
    if(pos==0)
    {
        struct Node<T>* q=first;
        if(first->next==NULL)
        delete(first);
        else
        {
            first=first->next;
            delete(q);
        }
    }
    else
    {
        struct Node<T>* q=NULL;
        for(int i=0;i<pos;i++)
        {q=p;
        p=p->next;}
        if(p->next==NULL)
        {
            q->next=NULL;
            delete(p);
        }
        else
        {
            q->next=p->next;
            delete(p);
        }
    }
}

template<class T> 
bool is_sorted(struct Node<T>* p)
{
    while(p->next)
    {
        if(p->next->data<p->data)return false;
        p=p->next;
    }
    return true;
}

template<class T> 
void remove_duplicates(struct Node<T>* p)
{
    // pointer to move forward to delete the common elements
    struct Node<T>*q=p;
    while(p->next)
    {
        p=p->next;
        if(q->data==p->data)
        {
            q->next=p->next;
            delete(p);            
        }
        q=p;
    }
}

template<class T> 
void r_remove_duplicate(struct Node<T>* p)
{
    // do nothing if empty list
    if(first==NULL)return;
    // pointer to the node to be deleted
    struct Node<T>* to_free;
    if(p->next)
    {
        if(p->data==p->next->data)
        {
            to_free=p->next;
            p->next=p->next->next;
            delete(to_free);
            r_remove_duplicate(p);
        }
        else
        {
            r_remove_duplicate(p->next);
        }
    }
}

template<class T> 
void reverse(struct Node<T>* p)
{
    /* using sliding pointer */
    struct Node<T>*r=NULL,*q=NULL;
    while(p)
    {
        q=r;
        r=p;
        p=p->next;
        r->next=q;
    }
    first=r;
}


template<class T> 
void r_reverse(struct Node<T>*q,struct Node<T>* p)
{
    if(p!=NULL)
    {
        r_reverse(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    create(A, 5);
    Node<int>* q=NULL;
    r_reverse(q,first);
    display(first);
}