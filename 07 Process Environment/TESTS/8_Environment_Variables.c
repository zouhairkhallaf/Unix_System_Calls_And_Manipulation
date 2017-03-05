#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for gentenv() */
int main(void)
{
    char *value=getenv("HOME");
    printf("%s\n", value);
    printf("%s\n", getenv("LANG"));
    printf("%s\n", getenv("LC_MONETARY"));
    return 0;
}