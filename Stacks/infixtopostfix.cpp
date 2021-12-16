#include <iostream>  
#include <stack>
#include <string> 

using namespace std;
 
bool is_operand(char ch)
{
    if(ch=='-' || ch=='*' || ch=='+' || ch=='/')return false;
    else return true;
}

int precedence(char ch)
{
    if(ch=='-' || ch=='+')return 1;
    else if(ch=='/' || ch=='*')return 2;
    else return 0;
}

string convert(string infix)
{
    stack<char> st;
    string postfix;
    int i=0; // to interate over infix expression
    while(infix[i]!='\0')
    {
        if(is_operand(infix[i]))
        {
            postfix.push_back(infix[i++]);     
        }
        else
        {
            if(st.empty() || precedence(infix[i])>precedence(st.top()))
                st.push(infix[i++]);
            else
            {    
                postfix.push_back(st.top());
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        st.push(st.top());
        st.pop();
    }
    return postfix;
}

int main()
{
    string exp="a+b*c-d/e";
    cout<<convert(exp);
}