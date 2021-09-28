#ifndef UPPER_TRIANGLE_H
#define UPPER_TRIANGLE_H
#include <iostream>

using namespace std;

class Matrix
{
    private:
    int n;
    int *A;

    public:
    Matrix(int n);
    void set_upper(int i, int j, int data);
    int get_upper(int i, int j);
    void display_upper();
};

Matrix::Matrix(int n)
{
    this->n=n;
    A=new int[n];
}

void Matrix::set_upper(int i, int j, int data)
{
    if(i<=j)
    {
        A[(i-1)*n - (i-1)*(i-2)/2 + (j-i)]=data;
    }

}

int Matrix::get_upper(int i, int j)
{
    if(i<=j)
    {
        return A[(i-1)*n - (i-1)*(i-2)/2 + (j-i)];
    }
    else
    return 0;
}

void Matrix::display_upper()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
            cout<<A[(i-1)*n - (i-1)*(i-2)/2 + (j-i)]<<" ";
            else
            cout<<"0 ";
        }
        cout<<"\n";
    }
}


#endif