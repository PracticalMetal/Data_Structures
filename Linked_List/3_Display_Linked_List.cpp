#include <iostream>  
 
using namespace std;
 
struct node
{
    int data;
    struct node *next;
}*first=NULL;                  // Global pointer to a linked list

int main()
{
    first=new node;
    struct node *p;
 
   while(p->next!=NULL)
   {
       cout<<p->data;
       p=p->next;
   }
}