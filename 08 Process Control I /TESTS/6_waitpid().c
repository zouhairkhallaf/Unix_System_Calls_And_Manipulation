#include <unistd.h> /* for read(), write() */
#include <fcntl.h> /* for open() */
#include <string.h> /* for strlen() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for calloc() */
#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int, char *);
int main(int argc, char *argv[])
{
    int *status_child;
    int fd=open("file6.txt",O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret=fork();
    int pid_child, pid_parent;
    char *whichProcess;
    if (ret==0) /* child process */
    {
        whichProcess="Child process:\n--------------------------\n";
        pid_child=getpid();
        printf("In child process: pid_child=%d\n", pid_child);
        Input(fd, whichProcess);
        sleep(2);
    }
    else /* parent process */
    {
        whichProcess="Parent process: \n--------------------------\n";
        pid_parent=getpid();
        pid_child=waitpid(pid_child, status_child, WNOHANG);
        printf("In parent process: pid_child=%d\n", pid_child);
        Input(fd, whichProcess);
    }
    return 0;
}
void Input(int filedes, char *process)
{
    ssize_t first_line=write(filedes, process,strlen(process));
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