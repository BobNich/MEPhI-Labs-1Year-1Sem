#include <stdio.h>
#include <math.h>

double polinom();
int abspower();

int main()
{
    double x,ss,rl;
    double e;
    int np;
    printf("Print x\n");
    scanf("%lf",&x);
    printf("Print e\n");
    scanf("%lf",&e);
    ss = polinom(x,e);
    np = abspower(e);
    printf("Ans is %.*lf\n",np,ss);
    rl = sqrt(1+x);
    printf("Real (with the given accuracy) is %.*lf",np,rl);
    return 0;
}


double polinom(double x, double e)
{
    double p = 1;
    double s = 1;
    int i = 1;
    while (fabs(p) > e)
    {
        p = (p * x*(3-2*i))/(2*i);
        if (fabs(p) > e)
        {
            s += p;
            i += 1;
        }
        else
        {
            return s;
        }
    }
}

int abspower(double e)
{
    int np = 0;
    while (e != 1)
    {
        e = e*10;
        np += 1;
    }
    return np;
}
