#include <bits/stdc++.h>
using namespace std;

int max_iteration = 1000; 
double precision = 10E-10;

//for example we use problem in ppt Komnum2 number 3a
double f(double x)
{
    return (pow(x,3)-(3*x)+1);
}

int main()
{
    double x1, x2;
    printf ("Input x1: ");
    scanf ("%lf", &x1);
    printf ("Input x2: ");
    scanf ("%lf", &x2);

    double a, b;
    a = f(x1);
    b = f(x2);

    if(a * b > 0) 
        puts("The numbers don't meet the Bolzano requirement by having the same sign");
    else
    {
        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");
        printf("iteration \t      x1\t\t     x2\t\t\t      xt\t\t     f(x1)\t\t     f(x2)\t\t     f(xt)\t\t\t");
        puts("");
        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");

        double xt;
        for(int i = 1; i <= max_iteration; i++)
        {
            xt = (x1 + x2) / 2;
            printf("  %d \t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t", i, x1, x2, xt, a, b, f(xt));
            puts("");

            //substitute xt with new boundaries near 0
            if((a >= 0 && f(xt) >= 0) || (a <= 0 && f(xt) <= 0))
            {
                x1 = xt;
                a = f(xt);
            }
            else 
            {
                x2 = xt;
                b = f(xt);
            }

            //end the program if f(xt) value already near the precision we wanted
            if(abs(f(xt)) < precision)
            {
                puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");
                printf("Root: %.15lf\n", xt);
                break;
            }   
        }
    }
    return 0;
}
