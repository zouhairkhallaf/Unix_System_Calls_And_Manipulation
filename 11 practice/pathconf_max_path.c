#include <stdio.h> /* for print */
#include <fcntl.h> /* for open() */
#include <unistd.h> /* for pathconf() */
#include <string.h> /* for strcat() */
#include <stdlib.h> /* for malloc() */
#include <errno.h> /* for errno */
int main(int argc, char *argv[])
{
    char *pathname;
    pathname="/Users/zouhairkhallaf/Desktop/";
    char filename[1000];
    
    for (int i=0; i<999; i++)
        (void) strcat(filename, "a");
    
    char *abs_path;
    
    if ( (abs_path=malloc(strlen(pathname)+strlen(filename)+1))!=NULL )
    {
        abs_path[0]='\0';
        strcat(abs_path, pathname);
        strcat(abs_path, filename);
    }
    else
        printf("malloc() failed\n");
    
    printf("Long path: %s\n", abs_path);
    int fd=open(abs_path, O_RDWR|O_CREAT|O_TRUNC);
    long e=pathconf(abs_path, _PC_NO_TRUNC);
    printf("%s\n", strerror(errno));
    
    return 0;
}