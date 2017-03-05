#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i;
    printf("Length of a tab is %lu\n", strlen("\t"));
    char *string="|\tS_IFBLK\t\t|\t%o\t\t|\n";
    for (i=0; i<strlen("|\tS_IFBLK\t\t|\t%o\t|\n"); i++)
    {
        if (string[i]=='\t')
            printf("------");
        else
            printf("-");
    }
    printf("-\n");
    printf("|\tS_IFBLK\t\t|\t%o\t\t|\n", S_IFBLK);
    printf("|\tS_IFCHR\t\t|\t%o\t\t|\n", S_IFCHR);
    printf("|\tS_IFDIR\t\t|\t%o\t\t|\n", S_IFDIR);
    printf("|\tS_IFIFO\t\t|\t%o\t\t|\n", S_IFIFO);
    printf("|\tS_IFREG\t\t|\t%o\t\t|\n", S_IFREG);
    printf("|\tS_IFLNK\t\t|\t%o\t\t|\n", S_IFLNK);
    printf("|\tS_IFSOCK\t|\t%o\t\t|\n", S_IFSOCK);
    for (i=0; i<strlen("|\tS_IFBLK\t\t|\t%o\t|\n"); i++)
    {
        if (string[i]=='\t')
            printf("------");
        else
            printf("-");
    }
        printf("-\n");
        return 0;
    }