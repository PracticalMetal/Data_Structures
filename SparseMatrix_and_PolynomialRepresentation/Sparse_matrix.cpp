#include <iostream>  
 
using namespace std;
 
/* creating a struct for storing elements which will be passed onto the sparse matrix struct */
struct Elements
{
    int rows,column,data;
};


struct Sparse
{
    // first values of the sparse matrix will include total row and column no
    int m;
    int n;
    int num;
    // dynamically declaring elements
    struct Elements *e; 
};


void create(struct Sparse *s)
{
    cout<<"Enter the dimension of the sparse matrix, input no. of rows followed by no. of columns: \n";
    cin>>s->m>>s->n;

    cout<<"Enter the number of non-zero elements: \n";
    cin>>s->num;

    // dynamic allocation
    s->e=new Elements[s->num];

    cout<<"Enter all the elements in the following order- \n 1. row number \n 2. column number \n 3. data \n";

    for(int i=0;i<s->num;i++)
    {
        cin>>s->e[i].rows>>s->e[i].column>>s->e[i].data;
    }
}


void display(struct Sparse s)
{
    // using a variable k to point at the current element in the sparse matrix and if the condition is satisfied it should print the element in the matrix
    int k=0;

    // using two loops iterate through the sparse matrix and display all the zero and non-zero elements
    for(int i=1;i<=s.m;i++)
    {   // j and i start from 1 assuming that  are following the mathematical repres of marices, for computer repres use 0
        for(int j=1;j<=s.n;j++)
        {
            if(i==s.e[k].rows && j==s.e[k].column)
            {
                cout<<s.e[k].data<<" ";
                k++;
            }
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

struct Sparse* add(struct Sparse s1, struct Sparse s2)
{
    if(s1.m!=s2.m || s1.n!=s2.n)return NULL;

    struct Sparse *sum;
    sum->m=s1.m;
    sum->n=s1.n;
    sum->e=new Elements[s1.num + s2.num];

    // declaring starting pointer
    int i,j,k;
    i=j=k=0;

    // comparing rows
    if(s1.e[i].rows < s2.e[j].rows)
        sum->e[k++]=s1.e[i++];
    
    if(s1.e[i].rows > s2.e[j].rows)
        sum->e[k++]=s2.e[j++];

    else
    {sum->e[k].rows=s1.e[i].rows;
    sum->e[k].column=s2.e[i].column;
    sum->e[k].data=s1.e[i].data+s2.e[j].data;

    i++;
    j++;
    k++;
    }

    // checking if there are any left over elements
    if(i<s1.num)
    {
        for(;i<s1.num;i++)
        {
            sum->e[k++]=s1.e[i];
        }
    }
    if(j<s2.num)
    {
        for(;j<s2.num;j++)
        {
            sum->e[k++]=s1.e[j];
        }
    }

    return sum;
}

int main()
{
    struct Sparse s1;
    create(&s1);
    struct Sparse s2;
    create(&s2);
    struct Sparse *s3=add(s1,s2);

    display(*s3);
}