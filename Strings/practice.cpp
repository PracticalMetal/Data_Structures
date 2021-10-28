#include <iostream>  
 
using namespace std;
 
int length_string(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {

    }
    return i;
}

void rev_string(char s[])
{
    int i,j;
    char new_string[50];
    for(i=0;s[i]!='\0';i++){}
    for(j=0;i>=0;i--,j++)
    {
        new_string[j]=s[i];
    }
    new_string[j]='\0';
    cout<<new_string;
}

void duplicate(char s[])
{
    /* using left shift <<
       using ORing to check to set the bit as on
       using ANDing to check if the bit is on */

    long int x=0,H=0,H2=0; // x is for checking if the bit is on or off and h i s like a hash table

    for(int i=0;s[i]!='\0';i++)
    {
        x=1; // setting x as one initially every time
        x=x<<s[i]-97;  // setting the current bit as on

        if((x & H)>0) // checking if the current bit is on or not
        {
            H2=(x&H)|H2;
        }
        else
        {
            H=x|H;
        }
    }   
    x=1;
    int count=0;
    while(count>=0 && count<=25)
    {
        if((x&H2)>0)
        cout<<char(count+97)<<" is duplicate. \n";
        x=x<<1;
        count++;
    }
}

int main()
{                                            
    char s[]="heellleo";
    duplicate(s);    
}