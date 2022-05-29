#include <stdio.h>

void find_km();

int main()
{
    int n;
    printf("Print your N\n");
    scanf("%d",&n);
    find_km(n);
    return 0;
}


void find_km(int n)
{
    int x,m,k,m1,k1;
    x = 1;
    m = 0;
    m1 = 0;
    while ( x != 0)
    {
        if(!((n - 5*m) % 3))
        {
            k = (n - 5*m) / 3;
            printf("m = %d, k = %d\n",m,k);
            x = 0;
        }
        else if(!((n - 5*m1) % 3))
        {
            k1 = (n - 5*m1) / 3;
            printf("m = %d, k = %d\n",m1,k1);
            x = 0;
        }
        else
        {
            m = m-1;
            m1 = m1+1;
        }
    }
}
