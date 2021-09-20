#include <iostream>  
#include <string>
 
using namespace std;
 
void backtracking(string s, int k)
{
    int i;
    static int A[10]={0};  // array to keep track of which element is taken and which is not taken
    static char ans[10];

    if(s[k]=='\0')
    {
        ans[k]='\0';
        cout<<ans<<" ";
    }

    for(i=0;s[i]!='\0';i++)
    {
        
        if(A[i]==0)  // means that letter is available
        {
            ans[k]=s[i];
            A[i]=1;
            backtracking(s,k+1);
            A[i]=0;
        }
    }
}

void backtracking_swap(string s, int l, int h)
{
    int i;
    if(l==h)cout<<s<<" ";
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(s[i],s[l]);
            backtracking_swap(s,l+1,h);
            swap(s[i],s[l]);
        }
    }
}

int main()
{
    string s="abc";
    backtracking_swap(s,0,2);
}