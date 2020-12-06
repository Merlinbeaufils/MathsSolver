#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>


class fraction
{
public:
    fraction()
    {
        a=0;
        b=1;
    }
    fraction(int x,int y)
    {
        a=x;
        b=y;
    }
    fraction(int x)
    {
        a=x;
        b=1;
    }

    fraction add(int x, int y);
    fraction minus(int x,int y);
    fraction times(int x, int y);
    fraction devide(int x, int y);

    void show()
    {
        std::cout<<a<<"/"<<b<<std::endl;
    }

private:
    int a,b;
};

int simpl(int x, int y)
{
    int a=x;
    int b=y;
    while( a!=0 and b!=0 )
    {
        if( a >= b )
        {
            a = a%b;
        }
        else
            if( b > a )
            {
                b = b%a;
            }
    }

    if( a >= b )
    {
        return a;
    }
    return b;

};

#endif // FRACTION_H
