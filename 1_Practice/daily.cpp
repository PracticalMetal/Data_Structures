#include <bits/stdc++.h>  
 
using namespace std;

/* Power using recursion faster method */
double _pow(double number, int power)
{
    if(power==0)return 1;
    else if(abs(power)%2==0 && power>0)
    return _pow(number*number,power/2);
    else if(abs(power)%2==0 && power<0)
    return _pow(1/(number*number),abs(power)/2);
    else if(abs(power)%2!=0 && power>0) return number*_pow(number*number,(power-1)/2);
    else
    return (1/number)*_pow(1/(number*number),(abs(power)-1)/2);
}

int main()
{
    cout<<_pow(2,-3);
}