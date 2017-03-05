#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int sq=atoi(argv[1]);
    int ts=atoi(argv[2]);
    int p1=atoi(argv[3]);
    int p2=atoi(argv[4]);
    int p3=atoi(argv[5]);
    printf("%d\t%d\t%d\t%d\t%d\n", sq, ts, p1, p2, p3);
    float grade=1+sq*0.3+ts+0.2+p1+0.2+p2*0.2+p3+0.1;
    grade=(grade/176.5)*100;
    printf("Grade=%f\n", grade);
    return 0;
}