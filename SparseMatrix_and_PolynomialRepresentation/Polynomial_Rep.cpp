#include <iostream>  
#include <math.h>
 
using namespace std;
 
struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void create()
{
    struct Poly p;
    cout<<"Enter non-zero elements: \n";
    cin>>p.n;
    p.t=new Term[p.n];

    cout<<"Enter polynomial terms and coefficient: \n";
    for(int i=0;i<p.n;i++)
    {
        cout<<"Enter the "<<i+1<<"th term: \n";
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
}

int val(struct Poly p, int x)
{
    int sum=0;
    for(int i=0;i<p.n;i++)
    {
        sum+=p.t[i].coeff*(pow(x,p.t[i].exp));
    }
    return sum;
}

struct Poly poly_addition(struct Poly p1, struct Poly p2)
{
    struct Poly p3;
    p3.n=p1.n+p2.n;
    p3.t=new Term[p3.n];

    int i,j,k;
    i=j=k=0;

    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].exp == p2.t[j].exp)
        {
            p3.t[k].coeff=p1.t[i].coeff+p2.t[j].coeff;
            p3.t[k++].exp=p1.t[i].exp;
            i++;
            j++;
        }
        else if(p1.t[i].exp > p2.t[j].exp)
        {
            p3.t[k].coeff=p1.t[i].coeff;
            p3.t[k++].exp=p1.t[i].exp;
            i++;
            
        }
        else
        {
            p3.t[k].coeff=p2.t[j].coeff;
            p3.t[k++].exp=p2.t[j].exp;
            j++;
        }
    }
    for(;i<p1.n;i++)
    {
        p3.t[k].coeff=p1.t[i].coeff;
        p3.t[k++].exp=p1.t[i].exp;
    }
    for(;j<p2.n;j++)
    {
        p3.t[k].coeff=p2.t[j].coeff;
        p3.t[k++].exp=p2.t[j].exp;
    }
}

int main()
{
    
}