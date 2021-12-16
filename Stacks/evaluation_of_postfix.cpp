#include <iostream>  
#include <stack>
#include <string> 

using namespace std;

bool is_operand(char ch)
{
    if(ch=='-' || ch=='*' || ch=='+' || ch=='/')return false;
    else return true;
}
 
int eval(string postfix)
{
    string infix;
    stack<int> st;

    int i=0;
    while(postfix[i]!='\0')
    {
        if(is_operand(postfix[i]))st.push(postfix[i]-'0');
        else
        {
            int a,b;
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            int c;
            switch(postfix[i])
            {
                case '+':
                c=a+b;break;
                case '-':
                c=a-b;break;
                case '*':
                c=a*b;break;
                case '/':
                c=a/b;break;
            }
            st.push(c);
        }
    }
    return st.top();

}

int main()
{
    cout<<eval("35*62/+4-");
}