#ifndef DIAGONAL_H
#define DIAGONAL_H
#include <iostream>

using namespace std;

struct Matrix
{
    int n;
    int A[50]={0};
};

void set_diagonal(struct Matrix *m, int i, int j, int data)
{
    if(i==j)
    {
        m->A[i-1]=data;
    }
}

int get_diagonal(struct Matrix m, int i, int j)
{
    if(i==j)return m.A[i-1];
    else return 0;
}

void display_diagonal(struct Matrix m)
{
    for(int i=0;i<m.n;i++)
    {
        for(int j=0;j<m.n;j++)
        {
            if(i==j)cout<<m.A[i-1]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}


#endif