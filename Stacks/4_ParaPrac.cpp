#include <iostream>  
#include <stack>
#include <string>

using namespace std;
 
int main()
{
    stack<char> st;
    string exp="((a+b))*((-d))";
    for(int i=0;i<exp.length();i++)
    {
        /* if there is an opening bracket push into the stack */
        if(exp[i]=='(')
        {
            st.push('(');
        }
        if(exp[i]==')')
        {
            if(st.empty())
            {cout<<"Not matching!";
            return 0;}
            else
            {
                st.pop();
            }
        }

    }
    if(st.empty())cout<<"Matched!";
    else
    cout<<"Not Matching!";

}