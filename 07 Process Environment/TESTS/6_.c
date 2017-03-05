#include <stdio.h>
int Factorial(int upperBound);
int main(void)
{
    int n=6;
    int fact=Factorial(n);
    printf("%d!=%d\n", n, fact);
    return 0;
}
int Factorial(int upperBound)
{
    auto int f;
    if (upperBound==0)
    {
        f=1;
    }
    else
    {
        for (int i=1; i<=upperBound; i++)
        {
            f=Factorial(i-1)*i;
        }
    }
    return f;
}