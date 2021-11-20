#include <iostream>  
 
using namespace std;
 
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *s);
void push(struct Stack *s, int data);
void display(struct Stack s);
int pop(struct Stack *s);
int peek(struct Stack s, int index);


int main()
{
    struct Stack st;
    create(&st);

    push(&st,1);
    push(&st,2);
    display(st);
    pop(&st);
    cout<<peek(st,0);
}

void create(struct Stack *s)
{
    cout<<"Enter the size of the array \n";
    cin>>s->size;
    s->S=new int[s->size];
    s->top=-1;
}

void push(struct Stack *s, int data)
{
    /* checking for stack full */
    
    if(s->top==s->size-1)
    {
        cout<<"Stack is full \n";
        return ;
    }
    s->top++;
    s->S[s->top]=data;
}

void display(struct Stack s)
{
    for(int i=0;i<=s.top;i++)cout<<s.S[i]<<" ";
    cout<<"\n";
}

int pop(struct Stack *s)
{
    int x=-1;
    /* checking for empty stack */
    if(s->top==-1)
    {
        cout<<"Stack is empty \n";
        return x;
    }
    x=s->S[s->top--];
    return x;

}

int peek(struct Stack s, int index)
{
    if(index<0 || index>s.size-1)return -1;
    return s.S[index];
}