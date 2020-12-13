#include "linearsystems.h"
#include<iostream>
using namespace std;

linearsystems::linearsystems()
{
    int n,m;
    std::cout<<"the number of unknows n=";
    std::cin >>n;
    std::cout<<"the number of equations m=";
    std::cin >>m;
    double a[m][n];
    double b[m];
    double xin;
    for (int i=0;i<m;i++)
    {
        for (int j=0; j<n;j++)
        {
            std::cin>>xin;
            a[i][j]=xin;
        }
        std::cin>>xin;
        b[i]=xin;

        cout<<"the equation "<< i << " is " ;
        for (int j=0; j<n-1 ; j++)
        {
            cout<< a[i][j] << "x_"<< j << " + " ;
        }
        cout<< a[i][n-1] << "x_"<< n-1 << " = "<<b[i] <<endl;
    }


    int i, j, k;
    double c[m];

    for (k = 0; k < n - 1; k++)
    {
        if (a[k][k]==0)
        {
            continue;
        }
        if (k>=m)
        {
            break;
        }

        for (i = k + 1; i < m; i++)
            c[i] = a[i][k] / a[k][k];


        for (i = k + 1; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }

    for (k = n-1; k>=0; k--)
    {
        if (k>=m)
        {
            continue;
        }
        if (a[k][k]==0)
        {
            continue;
        }

        for (i = k - 1; i >=0; i--)
            c[i] = a[i][k] / a[k][k];


        for (i = k - 1; i >=0; i--)
        {
            for (j = n-1; j >=0; j--)
            {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }

    cout << "Using Gaussin Elimation The equations is:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j=0; j<n-1; j++)
        {
            cout << a[i][j] << "x_" << j+1 << " + " ;
        }
        cout << a[i][n-1] << "x_" << n << " = "<< b[i] <<endl;
    }

    bool nsol=false;

    for (int i=0; i<m; i++)
    {
        int js=-1;
        for (int j=0; j<n; j++)
        {
            if (a[i][j]!=0)
            {
                js=j;
                break;
            }
        }
        if (js==-1)
        {
            if (b[i]!=0)
            {
                nsol=true;
            }
        }
        else
        {
            b[i]=b[i]/a[i][js];
            for (int j=0; j<n; j++)
            {
                if (j==js)
                    continue;
                a[i][j]=a[i][j]/a[i][js];
            }
            a[i][js]=1;
        }
    }
    if (nsol==true)
    {
        cout<<"no solution"<<endl;
    }
    else
    {
        cout << "The solution is:" << endl;
        for (i = 0; i < m; i++)
        {
            bool f=false;
            for (j=0; j<n-1; j++)
            {
                if (a[i][j]!=0)
                {
                    if (f)
                    {
                        cout<<"+";
                    }
                    cout << a[i][j] << "x_" << j+1  ;
                    f=true;
                }
            }
            if (a[i][n-1]>0)
            {
                if (f)
                {
                    cout<<"+";
                }
                cout << a[i][n-1] << "x_" << n ;
                f=true;
            }
            if (f)
            {
                cout<<" = "<< b[i] <<endl;
            }
        }
    }

}

int main()
{
    linearsystems();
    return 0;
}
