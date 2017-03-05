#include <unistd.h> /* for read(), write() */
#include <fcntl.h> /* for open() */
#include <string.h> /* for strlen() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for calloc() */
#include <stdbool.h> /* for true */
#include <sys/wait.h> /* for the macros */
#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int);
void PrintStatus(int status);
int main(int argc, char *argv[])
{
    int *status_child=malloc(sizeof(int));
    int fd=open("file4.txt",O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret=fork();
    if (ret==0) /* child process */
    {
        Input(fd);
        sleep(2);
    }
    else /* parent process */
    {
        int pid_child=wait(status_child);
        printf("pid_child=%d\n", pid_child);
        printf("status_child=%d\n", *status_child);
        PrintStatus(*status_child);
        free(status_child);
        Input(fd);
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
        printf("Exit status for child=%d\n", status);
        printf("lower_8_bits=%x\n", status);
    }
    else if (WIFSIGNALED(status)==true)
        printf("Exit status for child=%d\n", status);
    else if (WIFSTOPPED(status)==true)
        printf("Exit status for child=%d\n", status);
}