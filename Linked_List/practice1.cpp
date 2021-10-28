#include <bits/stdc++.h>  
 
using namespace std;
using namespace std::chrono;

struct node
{
    int data;
    node *next;
}*first=NULL, *second=NULL, *third=NULL;

node* Create(int A[],int n)
{
    node *t,*last, *head;
    t=new node;
    t->data=A[0];
    t->next=NULL;
    head=t;
    for(int i=1;i<n;i++)
    {
        last=new node;
        last->data=A[i];
        t->next=last;
        t=last;
    }
    return head;

    
}

void Display(node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void rDisplay(node *p)
{
    if(p)
    {cout<<p->data<<" ";
    rDisplay(p->next);}
}

int Count(node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

int rCount(node *p)
{
    if(!p)
    return 0;
    else
    return 1+rCount(p->next);
}

int Sum(node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;

}

int rSum(node *p)
{
    if(!p)return 0;
    return p->data+rSum(p->next);
}

int Maxim(node *p)
{
    int Max=first->data;
    p=p->next;
    for(int i=1;i<Count(first);i++)
    {
        if(p->data>Max)Max=p->data;
        p=p->next;
    }
    return Max;
}

int rMaxim(node *p)
{
    if(!p)return INT_MIN;
    int x=p->data;
    return x>rMaxim(p->next)?x:rMaxim(p->next);
}

node* Search(node *p,int key)
{
    while(p)
    {
        if(p->data==key)
        return p;
        p=p->next;
    }
    return NULL;
}

node* rSearch(node *p,int key)
{
    if(!p)return NULL;
    if(p->data==key)return p;
    else return rSearch(p->next,key);
}

node* improveSearch(node *p,int key)
{
    node *q=NULL;
    while(p)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;
    }
    return NULL;

}

void Insert(node *p,int x,int pos=1)
{
    node *q=NULL,*t;
    t=new node;
    t->data=x;

    if(pos==1)
    {
        if(first==NULL)
        {
            first=new node;
            first->data=x;
            first->next=NULL;
        }
        else
        {
            
            t->next=first;
            first=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=t;
        t->next=p;
    }
}

void Pop_back(node *p, int data)
{
    node *t,*q=NULL;
    t=new node;
    t->data=data;
    t->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
    }
    q->next=t; 
}

void insertInSorted(node *p,int data)
{
    node *q=NULL;
    node *t=new node;
    t->data=data;
    t->next=NULL;

    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<data)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=p;
            first=t;
        }
        else
        {q->next=t;
        t->next=p;}
    }
}

void insertInSorted2(node *p,int data)
{
    node *q=NULL;
    node *t=new node;
    t->data=data;
    t->next=NULL;

    while(p && data>p->data)
    {
        q=p;
        p=p->next;
    }

    if(p==first)
    {
        t->next=p;
        first=t;
    }
    else
    {
        q->next=t;
        t->next=p;
    }
}

void Delete(node *p,int pos)
{
    node *q;
    if(first==NULL)
    {
        cout<<"No value to be deleted\n";
        
    }
    else if(pos==1)
    {
        p=first;
        first=first->next;
        delete p;
    }
    else
    {   int count=1;
        while(p && count!=pos)
        {
            q=p;
            p=p->next;
            count++;
        }
        if(p)
        {q->next=p->next;
        delete p;}
    }

}

bool isSorted(struct node *p)
{
    if(first==NULL)return true;
    while(p->next)
    {
        if(p->data>p->next->data)
        return false;
        p=p->next;
    }
    return true;
}

void remove_duplicate_from_sorted(struct node *p)
{
    node *q;
    q=p->next;

    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void remove_duplicate_one_pointer(struct node *p)           // recursive approach
{
    node *to_free;
    if(first==NULL)return;    /* checking for empty list */

    if(p->next!=NULL)
    {
        if(p->data==p->next->data)
        {
            to_free=p->next;   /* bring the node to be freed to p's next */
            p->next=p->next->next;    /* moving the pointer to the node to the next node */
            free(to_free);  /* freeing the node */

            remove_duplicate_one_pointer(p);  /* calling the recursion on the current node */

        }
        else
        {
            remove_duplicate_one_pointer(p->next);  /* calling the recursive call onto the next node */
        }
    }
}

void reverse_using_array(struct node *p)
{
    int arr[Count(p)];
    int i=0;
    while(p)
    {
        arr[i++]=p->data;
        p=p->next;       
    }
    i--;p=first;
    while(p)
    {
        p->data=arr[i--];
        p=p->next;
    }
}

void reverse_using_sliding_pointers(struct node *p)
{
  node *q=NULL,*r=NULL;

  /* using sliding pointers */
  while(p)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
    first=q;
  }
    
}

void reverse_using_recursion(struct node *q, struct node *p)
{
    if(p!=NULL)
    {
        reverse_using_recursion(p,p->next);     /* to reach the end of the LL */
        p->next=q;                              /* switching links with each recursive call */                                      
    }
    else
    {
        first=q;                                /* at the last recursive call assign first as q */
    }
}

void concat(struct node *p, struct node *q)
{
    while(p->next)p=p->next;
    p->next=q;
}

void _merge(struct node *p, struct node *q)
{
    node *last=NULL;    /* declaringpointer which will act as the third and end of the merged linked list */

    /* setting ptrs to lesser value out of both the linked list */
    if(p->data < q->data)
    {
        third=last=p;        /* set */
        p=p->next;           /* move */
        last->next=0;        /* null */
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p && q)           /* till either of them reach the end */
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=0;
        }

    }
    if(p)last->next=p;
    else last->next=q;
    
}

bool is_loop(struct node* p)
{
    node *q=p;
    do
    {
        p=p->next;
        q=q->next;

        q=q!=NULL?q->next:NULL;       /* checking if q has reached the end of then linked list, if so assign it as NULL */

    } while (p!=q && q && p);

    if(p==q)return true;
    else
    return false;
    
}

int main()
{
    int a[]={1,21,32,43,54};
    first=Create(a,5);

    int b[]={36,37,86,96,106};
    second=Create(b,5);

    node *f=second;
    while(f->next)f=f->next;
    f->next=second;

    cout<<is_loop(second);
    // Display(third);
    
}