#include <iostream>  
#include <string>
#include <stack>

using namespace std;
 
int main()
{
    stack<char> st;
    string exp="{([a+b)*[c-d]](/e}";

    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            st.push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(st.empty())
            {
                cout<<"Not matching!"<<endl;
                break;
                
            }
            else
            {
                char x;
                x=st.top();
                if(x>exp[i])
                {
                    cout<<"Not matching!"<<endl;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    if(st.empty())cout<<"Matched!";
    else cout<<"Not matching!";
}