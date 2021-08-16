#include <iostream>
#include <string> 
#include <string.h> 
 
using namespace std;

struct Stack
{
    int size;
    int top;
    char *s;        /* since it will point to a character */
}*top=NULL; 

void _push_back(struct Stack *st, int x)      /* stack is being modified therefore we are passing it by address */
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

int _pop(struct Stack *st)
{   
    int x=-1;
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

bool is_empty(struct Stack st)
{
    if(st.top==-1)return 1;
    else
    return 0;

    // Time: O(1)
}

bool is_full(struct Stack st)
{
    if(st.top=st.size-1)return 1;
    else
    return 0;

    // Time: O(1)
}

int is_balance(char *ch)
{
    struct Stack st;
    st.size=strlen(ch);
    /* assuming the maximum number of brackets can be equal to the size of the character array */
    st.s=new char[st.size];
    st.top=-1;

    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='(')
        _push_back(&st,ch[i]);
        else if(ch[i]==')')
        {
            if(st.top==-1)return false;   /* if stack is empty that means there is nothing to balanc which means its unbalanced */
            _pop(&st);
        }
    }
    if(st.top==-1)   /* after coming out of the loop if the stack is empty */
    return true;
    else
    return false;

} 
// fix this code 
bool is_balanced(char *ch)
{
    /* checking for balance as well as the matching bracket as well */
    struct Stack st;
    st.size=strlen(ch);
    st.top=-1;
    st.s=new char[st.size];

    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='(' || ch[i]=='['  || ch[i]=='{' )_push_back(&st,ch[i]);
        else if(ch[i]==')' || ch[i]==']'  || ch[i]=='}' )
        {
            if(st.top==-1)return false;
            char x=_pop(&st);
            
            switch(x)
            {
                case '(':
                if(ch[i]!=')')return false;
                case '[':
                if(ch[i]!=']')return false;
                case '{':
                if(ch[i]!='}')return false;
            }
        }
    }
    return st.top==-1?true:false;
}

int main()
{
    char ch[]="{(})";
    cout<<is_balance(ch);
}