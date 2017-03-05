#include <unistd.h> /* for read(), write()  */
#include <fcntl.h>  /* for open()           */
#include <string.h> /* for strlen()         */
#include <stdio.h>  /* for printf()         */
#include <stdlib.h> /* for calloc()         */
#define BUFFSIZE 4096
#define FILESIZE 1474560
int Input(int);
int main(int argc, char *argv[])
{
    int fd=open("file3.txt",O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret1=Input(fd);
    int ret2=Input(fd);
    if (ret1==0) /* child process */
    {
        printf("Child process, ret1=%d.\n", ret1);
        printf("PID1=%d.\n", getpid());
    }
    else if (ret2==0)
    {
        printf("Child process, ret2=%d.\n", ret2);
        printf("PID2=%d.\n", getpid());
    }
    else /* parent process */
    {
        printf("Parent process, ret1=%d.\n", ret1);
        printf("PID=%d.\n", getpid());
        printf("Parent process, ret2=%d.\n", ret2);
        printf("PID=%d.\n", getpid());
    }
    return 0;
}
int Input(int filedes)
{
    int r;
    r=fork();
    char **name=calloc(3, 20*sizeof(char));
    char **it;
    name[0]="Adriana Wise\n";
    name[1]="Richard Stevens\n";
    name[2]="Evi Nemeth\n";
    for (it=&name[0]; *it!=NULL; it++)
    {
        ssize_t num_bytes=write(filedes, *it, strlen(*it));
        sleep(2);
    }
    return r;
}