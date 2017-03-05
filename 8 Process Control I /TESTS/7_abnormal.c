#include <unistd.h> /* for read(), write() */
#include <fcntl.h> /* for open() */
#include <string.h> /* for strlen() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for calloc() */
#include <stdbool.h> /* for true */
#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int);
void PrintStatus(int status);
int main(int argc, char *argv[])
{
    int fd=open("file7.txt",O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret, status;
    for (int n=0; n<3; n++)
    {
        if ((ret=fork())==0) /* child process */
        {
            Input(fd);
            printf("Child process, ret=%d.\n", ret);
            status=wait(&status);
            switch(n)
            {
                case 0:
                    exit(7);
                    break;
                case 1:
                    abort();
                    break;
                case 2:
                    status=status/0;
                    break;
            }
        }
        else
        {
            printf("Parent process, child ret==%d.\n", ret);
            wait(&status);
            PrintStatus(status);
        }
    }
    return 0;
}
void Input(int filedes)
{
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
}
void PrintStatus(int status)
{
    int lower_8_bits;
    if ((lower_8_bits=WIFEXITED(status))==true)
    {
        printf("WIFEXITED(status)=%d\n"     ,WIFEXITED(status));
        printf("Exit status for child=%d\n" ,WEXITSTATUS(status));
        printf("lower_8_bits=%x\n", status);
    }
    else if (WIFSIGNALED(status)==true)
    {
        printf("WIFSIGNALED(status)=%d\n"   ,WIFSIGNALED(status));
        printf("Exit status for child=%d\n" ,WTERMSIG(status));
        printf("Exit status for child=%d\n" ,WCOREDUMP(status));
    }
    else if (WIFSTOPPED(status)==true)
    {
        printf("WIFSTOPPED(status)=%d\n"    ,WIFSTOPPED(status));
        printf("Exit status for child=%d\n" ,WSTOPSIG(status));
    }
}