#include <iostream>  
#include "symmetric.h"
 
using namespace std;
 
int main()
{
   int d;
   cout<<"Enter dimensions";
   cin>>d;
   Matrix m(d);
   for(int i=1;i<=d;i++)
   {
       for(int j=1;j<=d;j++)
       {    
           int x;
           cin>>x;
           m.set_symmetric(i,j,x);
       }
   }  
   m.display_symmetric();
}