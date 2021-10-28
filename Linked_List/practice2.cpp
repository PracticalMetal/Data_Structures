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


int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    create(A, 5);

    improved_seach(first,4);
    improved_seach(first,4);
}