#include <iostream>  
 
using namespace std;

class Lower_Triangle
{
    private:
    int n;
    int *A;

    public:
    Lower_Triangle(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~Lower_Triangle(){delete []A;}

};

void Lower_Triangle::set(int i,int j,int x)
{
    if(i>=j)
    A[(i*(i-1)/2)+(j-1)]=x;
    
}

int Lower_Triangle::get(int i,int j)
{
    if(i>=j)return A[(i*(i-1)/2)+(j-1)];
    else return 0;
}

void Lower_Triangle::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)cout<<A[(i*(i-1)/2)+(j-1)]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}
 
int main()
{
    int dimensions;
    cout<<"Enter dimnesion of the square of matrix\n";
    cin>>dimensions;
    Lower_Triangle m1(dimensions);
    for(int i=1;i<=dimensions;i++)
    {
        for(int j=1;j<=dimensions;j++)
        {
            int x;
            cin>>x;
            m1.set(i,j,x);
        }
    }
    m1.display();


}