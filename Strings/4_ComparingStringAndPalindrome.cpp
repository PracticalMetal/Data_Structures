#include <iostream>  
#include<string>
#include<cstdio>
 
using namespace std;

int comparing(char ch1[],char ch2[])
{
  int i=0;
  while(ch1[i]!='\0' && ch2[i]!='\0')
  {
    if(ch1[i]==ch2[i])
    i++;
    else if(ch1[i]>ch2[i])
    {
      cout<<ch2<<" appears before\n";
      return 0;
    }
    else
    {
      cout<<ch1<<" appears before\n";
      return 0;
    }

  }

  if(ch1[i]!='\0')
  cout<<ch2<<" appears before";
  else
  cout<<ch1<<" appears before";
  return 0;
}

int palindrome(char ch[])
{
  int i=0;
  for(;ch[i]!='\0';i++){}
  i--;
  int j=0,k=i;
  
  for(;j<=i,k>=0;j++,k--)
  {
    if(ch[j]!=ch[k])
    return 0;
  }
  cout<<"yes\n";
  return 0;
}
 
int main()
{
  char ch1[]="azza";
  char ch2[]="painting";

  comparing(ch1,ch2);
  palindrome(ch1);

  
  
}