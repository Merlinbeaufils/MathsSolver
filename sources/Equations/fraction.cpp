#include "fraction.h"
#include<iostream>

fraction fraction::add(int x, int y)
{
    a= a*y+b*x;
    b= b*y;
    int m;
    m=simpl(a,b);
    a=int(a/m);
    b=int(b/m);
}

fraction fraction::minus(int x, int y)
{
    a= a*y-b*x;
    b= b*y;
    int m;
    m=simpl(abs(a),b);
    a=int(a/m);
    b=int(b/m);
}

fraction fraction::times(int x, int y)
{
    a= a*x;
    b= b*y;
    int m;
    m=simpl(a,b);
    a=int(a/m);
    b=int(b/m);
}

fraction fraction::devide(int x, int y)
{
    a= a*y;
    b= b*x;
    int m;
    m=simpl(a,b);
    a=int(a/m);
    b=int(b/m);
}

int main()
{
    int a,b;
    std::cin>>a>>b;
    fraction f=fraction(a,b);
    f.devide(20, 1);
    f.show();
    return 0;
}
