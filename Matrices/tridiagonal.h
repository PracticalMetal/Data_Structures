#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H

#include <iostream>

using namespace std;

class Matrix
{
    private:
    int n;
    int *A;

    public:
    Matrix();
    void set_tri(int i, int j, int data);
    int get_tri(int i, int j);
    void display();
};



#endif