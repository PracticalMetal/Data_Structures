#include <iostream>  
#include<algorithm> 
using namespace std;

void reversingTwoLoops(char a[])
{
    char b[7];

    int i,j;
    
    for(i=0;a[i]!='\0';i++){}       //Finding the length of the string
    i--;                            //Decrementing i since its at \0
    for(j=0;i>=0;j++,i--)           //From the last of string 'a' inputing values in string 'b'
    b[j]=a[i];

    b[j]='\0';                      //To make a string
    cout<<b;
}

void reversingSingleLoop(char a[])
{
    int i,j;
    for(i=0;a[i]!='\0';i++){}
    i--;
    for(j=0;i>j;i--,j++)
    swap(a[i],a[j]);

    cout<<a;

}
 
int main()
{
    char a[]="helloo";
    reversingTwoLoops(a);
    cout<<"\n";
    reversingSingleLoop(a);
    
}