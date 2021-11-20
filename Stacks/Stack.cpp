#include <iostream>  
 
using namespace std;
 
/* implementing a stack using a linked list */
template<class T>
struct Node
{
    T data;
    struct Node *next;
};
template<class T>
struct Node<T> *top=NULL;

template<class T>
void push_back(struct Node<T> *st, T data)
{
    struct Node<T> *t;
    t=new Node<T>;
    /* checking for overflow */
    if(t==NULL)
    {
        cout<<"Overflow!";
        return;
    }
    t->data=data;
    t->next=top<T>;
    (top<T>)=t;
}

template<class T>
void display(struct Node<T> *st)
{
    while(st)
    {
        cout<<st->data<<" ";
        st=st->next;
    }
    cout<<"\n";
}

template<class T>
T pop(struct Node<T> *st)
{
    if(st==NULL)
    {
        cout<<"Underflow!";
        return -1;
    }
    auto x=st->data;
    (top<T>)=(top<T>)->next;
    return x;
}


int main()
{
    struct Node<char> *st;
    push_back(st,'c');
    pop(top<char>);
    display(top<char>);
}