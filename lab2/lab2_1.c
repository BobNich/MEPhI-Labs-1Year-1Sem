#include <stdio.h>

double polinom();

int main()
{
    double x,ss;
    int n;
    printf("Print x\n");
    scanf("%lf",&x);
    printf("Print n\n");
    scanf("%d",&n);
    ss = polinom(x,n);
    printf("Ans is %lf",ss);
    return 0;
}


double polinom(double x, int n)
{
    double p = 1;
    double s = 1;
    for (int i = 1; i <= (n-1); i++)
    {
        p = (p * x*(3-2*i))/(2*i);
        s += p;
    }

    return s;
}
