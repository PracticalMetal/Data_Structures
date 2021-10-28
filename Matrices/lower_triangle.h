#ifndef LOWER_TRIANGLE_H
#define LOWER_TRIANGLE_H
#include <iostream>

using namespace std;

class Matrix
{
    private:
    int n;
    int *A;

    public:
    Matrix(int n);
    void set_lower(int i, int j, int data);
    int get_lower(int i, int j);
    void display_lower();
};

Matrix::Matrix(int n)
{
    this->n=n;
    A=new int[n];
}

void Matrix::set_lower(int i, int j, int data)
{
    if(i>=j)
    {
        A[(i*(i-1)/2)+(j-1)]=data;
    }

}

int Matrix::get_lower(int i, int j)
{
    if(i>=j)
    {
        return A[(i*(i-1)/2)+(j-1)];
    }
    else
    return 0;
}

void Matrix::display_lower()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            cout<<A[(i*(i-1)/2)+(j-1)]<<" ";
            else
            cout<<"0 ";
        }
        cout<<"\n";
    }
}

#endif