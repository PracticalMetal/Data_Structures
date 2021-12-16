#include <iostream>  
 
using namespace std;
 
struct Stack
{
    int size;
    int top;
    int *S; // we will define the stack array dynamically in heap
};

void display(struct Stack st)
{
    if(st.top==-1)
    {
        cout<<"Stack is empty";
    }
    else
    {
        for(int i=st.top;i>=0;i++)
        cout<<st.S[i]<<" ";
    }
    cout<<"\n";
}

void push(struct Stack *st, int data)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack Overflow\n";
    }
    else
    {
        st->top++;
        st->S[st->top]=data;
    }
}

int pop(struct Stack *st)
{
    /* checking for underflow */
    if(st->top==-1)
    {
        cout<<"Stack underflow\n";
        return 0;
    }
    else
    {
        int x=-1;
        x=st->S[st->top];
        st->top--;
        return x;
    }
}

void peek(struct Stack st, int index)
{
    /* checking for underflow */
    if(st.top==-1)return ;
    cout<<st.S[st.top-index+1]<<" "<<"\n";
}
int main()
{
    struct Stack st;
    st.top=-1; /* initially set to -1 */
    st.size=5;
    st.S=new int[st.size];    
    push(&st,1);
    push(&st,2);
    peek(st,2);
}