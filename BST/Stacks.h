#ifndef Stacks_h
#define Stacks_h


#include <iostream>  
  
 using namespace std;

 /* for implementation of stack we use structure */

 struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;

struct Stack
{
    int size;
    int top;
    Node **s;  /* instead of defining a fixed size array we define a pointer which will point to a dynamically defined array */

};



void _push_back(struct Stack *st, Node *x)      /* stack is being modified therefore we are passing it by address */
{
    if(st->top==st->size-1)
    {
        cout<<"Stack overflow \n";  
    }
    /* checkin for overflow */
    else
    {
        st->top++;   /* increasing top to next position */
        st->s[st->top]=x;
    }

    // Time: O(1)
}

Node* _pop(struct Stack *st)
{   
    Node* x=NULL;
    /* checking for empty stack, as we cannot pop from a empty stack */
    if(st->top==-1)
    cout<<"Stack underflow \n";
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;  
    /* if we do not go into else part this fnc will return -1 */

    // Time: O(1)
}

Node* peek(struct Stack st, int pos)
{   
    Node* x=0;
    /* formula is Index=top-pos+1; */
    if(st.top-pos+1<0)cout<<"Invalid position \n";
    else
    {
        x=st.s[st.top-pos+1];
    }
    return x;

    // Time: O(1)
}

Node* stack_top(struct Stack st)
{
    if(st.top==-1)return NULL;
    else
    return st.s[st.top];

    // Time: O(1)
}

bool is_empty_stack(struct Stack st)
{
    if(st.top==-1)return 1;
    else
    return 0;

    // Time: O(1)
}

bool is_full(struct Stack st)
{
    if(st.top==st.size-1)return 1;
    else
    return 0;

    // Time: O(1)
}

void display(struct Stack st)
{
    if(st.top==-1)cout<<"Underflow \n";
    else
    {
        for(int i=st.top;i>=0;i--)
        cout<<st.s[i];
    }
}

void create_stack(struct Stack *st, int size)
{
    // cout<<"Enter the size of stack \n";
     st->size=size;
     st->s=new Node*[st->size];

     st->top=-1;
}

#endif