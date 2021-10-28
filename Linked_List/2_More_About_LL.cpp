#include <iostream>  
 
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *p,*q;
    p= new node;

    cout<<p->next;

}