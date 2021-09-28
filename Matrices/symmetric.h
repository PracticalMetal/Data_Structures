#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include <iostream>

using namespace std;

class Matrix
{
    private:
    int n; 
    int *A;

    public:
    Matrix(int n=2){this->n=n;A=new int[n];}
    void set_symmetric(int i, int j, int data);
    int get_symmetric(int i, int j);
    void display_symmetric();
};

void Matrix::set_symmetric(int i, int j, int data)
{
    if(i>=j)
    {
        A[i*(i-1)/2 + j-1]=data;
    }
    // else
    // A[j*(j-1)/2 + i-1]=data;
}

int Matrix::get_symmetric(int i, int j)
{
    if(i<=j)return A[i*(i-1)/2 + j-1];
    else return A[j*(j-1)/2 + i-1];
}

void Matrix::display_symmetric()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)cout<<A[i*(i-1)/2 + j-1]<<" ";
            else cout<<A[j*(j-1)/2 + i-1]<<" ";
        }
        cout<<"\n";
    }
}

#endif