#include <iostream>  
 
using namespace std;

void duplicatesHashing(char ch1[])
{
    int hash[128]={0};
    for(int i=0;ch1[i]!='\0';i++)

    {
        if(ch1[i]<91)
        ch1[i]+=32;
        hash[ch1[i]]++;
    }
    

    int j=65;
    while((j>=65&&j<=90) || (j>=97 &&j<=122))
    {

        if(hash[j]>1)
        cout<<(char)j<<" appeared "<<hash[j]<<" times.\n";

        j++;
        if(j==91)
        j=97;
    }
}
 
void duplicatesBitwise(char ch1[])
{
    //can only check if same character is present or not but cannot count
    int h=0,x=0;

    int i;
    for(i=0;ch1[i]!='\0';i++)
    {
        x=1;
        x=x<<ch1[i]-97;
        if(x&h>0)
        {
            cout<<ch1[i]<<" is duplicate\n";

        }
        else
        h=h|x;
    }
}



int main()
{
    char ch1[]="pulkitT";
    char ch2[]="aktsihit";

    //duplicatesHashing(ch1);
    duplicatesBitwise(ch2);
}