#include <iostream>  
 
using namespace std;

void display(struct node *p)
{
    do{
        cout<<p->data;
        p=p->next;
    }
    while(p!=HEAD);
}

void rDisplay(struct node *p)
{
    static int flag=0;
    if(p!=HEAD || flag==0)
    {
    flag=1;
    cout<<p->data;
    rDisplay(p->next);
    }
    flag=0;
}

int main()
{
    
}