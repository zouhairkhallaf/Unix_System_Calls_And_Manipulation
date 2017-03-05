#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for malloc() */
int main(void)
{
    char **myarray=malloc(2*10*sizeof(char));
    printf("%lu\n", 2*10*sizeof(char));
    myarray[0]="Adriana";
    myarray[1]="Wise";
    char **iterator;
    for (iterator=&myarray[0]; iterator!=&myarray[2]; iterator++)
    {
        printf("*%s*\n", *iterator);
    }
    char **myarray2=calloc(2, 10*sizeof(char));
    myarray2[0]="Ludwig van";
    myarray2[1]="Beethoven";
    for (iterator=&myarray2[0]; iterator!=&myarray2[2];
         iterator++)
    {
        printf("*%s*\n", *iterator);
    }
    myarray=realloc(myarray, 2*5*sizeof(char));
    myarray[0]="Felix";
    myarray[1]="Mendelssohn-Bartoldi";
    int j = 0;
    for (iterator=&myarray[0]; iterator!=&myarray[2]; iterator++)
    {
        printf("*%s*\n", myarray[j]);
        j++;
    }
    return 0;
}