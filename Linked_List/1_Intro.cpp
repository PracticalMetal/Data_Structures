#include <iostream>  
 
using namespace std;

// Declaring a self referential structure
struct node
{
    int data;
    struct node *next;
};

 
int main()
{   // Declaring a pointer to the linked list
    struct node *p;
    p=new node;

    // Accessing data
    p->data=10;
    p->next=0;     //0 = NULL

    
}