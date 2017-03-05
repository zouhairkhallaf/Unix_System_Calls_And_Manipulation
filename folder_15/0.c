#include <unistd.h>     /* for read(), write() */
#include <fcntl.h>      /* for open()          */
#include <string.h>     /* for strlen()        */
#include <stdio.h>      /* for printf()        */
#include <stdlib.h>     /* for calloc()        */
#include <stdbool.h>    /* for true            */
#include <sys/types.h>  /* for the sigevent    */
#include <sys/time.h>
#include <sys/resource.h>

#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int);
void PrintStatus(int status);
void Get_rusage(int status);
void Display_exit_signals(int signal);

int main(int argc, char *argv[])
{
    int fd=open("/Users/awise/Stevens/Lecture10/file5.txt", O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret, status;
    for (int n=0; n<3; n++)
    {
        if ((ret=fork())==0) /* child process */
        {
            Input(fd);
            printf("\n\nChild process, ret=%d.\n", ret);
            Get_rusage(&status);                                               /* Printing the rusage struct members for the Child */
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
            printf("\n\nParent process, child ret==%d.\n", ret);
            Get_rusage(&status);                                               /* Printing the rusage struct members for the Child */
            wait(&status);
            PrintStatus(status);
        }
    }
    printf("\n\n");
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
        printf(".WIFEXITED(status)     = %d\n"    , WIFEXITED(status));
        printf(".Exit status for child = %d\n", WEXITSTATUS(status));
        Display_exit_signals(WEXITSTATUS(status));     // This will print the Appropriate signal error with description
        printf(".lower_8_bits          = %x\n", status);
    }
    else if (WIFSIGNALED(status)==true)
    {
        printf(".WIFSIGNALED(status)    = %d\n"  , WIFSIGNALED(status));
        printf(".Exit status for child  = %d\n", WTERMSIG(status));
        Display_exit_signals(WTERMSIG(status));      // This will print the Appropriate signal error with description
        printf(".Exit status for child  = %d\n", WCOREDUMP(status));
        Display_exit_signals(WCOREDUMP(status));     // This will print the Appropriate signal error with description

    }
    else if (WIFSTOPPED(status)==true)
    {
        printf(".WIFSTOPPED(status)      = %d\n"   , WIFSTOPPED(status));
        printf(".Exit status for child   = %d\n", WSTOPSIG(status));
        Display_exit_signals(WSTOPSIG(status));     // This will print the Appropriate signal error with description

    }
}

void Get_rusage(int status){
    struct timeval {
        time_t      tv_sec;
        suseconds_t tv_usec;
    };
    struct rusage usage;
    wait3(&status, WNOHANG, &usage); /* Fills the rusage struct members */
    getrusage(RUSAGE_SELF, &usage);  /* Gets the rusage struct members ready to display*/
    printf ("PRINTING \"struct rusage usage\" for this Process :  \n");
    printf ("\ttimeval ru_utime  : %ld.%06d\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    printf ("\ttimeval ru_stime  : %ld.%06d\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf ( "\tlong   ru_maxrss  : %ld\n" , usage.ru_maxrss    ); /* maximum resident set size     */
    printf ( "\tlong   ru_ixrss   : %ld\n" , usage.ru_ixrss     ); /* integral shared memory size   */
    printf ( "\tlong   ru_idrss   : %ld\n" , usage.ru_idrss     ); /* integral unshared data size   */
    printf ( "\tlong   ru_isrss   : %ld\n" , usage.ru_isrss     ); /* integral unshared stack size  */
    printf ( "\tlong   ru_minflt  : %ld\n" , usage.ru_minflt    ); /* page reclaims                 */
    printf ( "\tlong   ru_majflt  : %ld\n" , usage.ru_majflt    ); /* page faults                   */
    printf ( "\tlong   ru_nswap   : %ld\n" , usage.ru_nswap     ); /* swaps                         */
    printf ( "\tlong   ru_inblock : %ld\n" , usage.ru_inblock   ); /* block input operations        */
    printf ( "\tlong   ru_oublock : %ld\n" , usage.ru_oublock   ); /* block output operations       */
    printf ( "\tlong   ru_msgsnd  : %ld\n" , usage.ru_msgsnd    ); /* messages sent                 */
    printf ( "\tlong   ru_msgrcv  : %ld\n" , usage.ru_msgrcv    ); /* messages received             */
    printf ( "\tlong   ru_nsignals: %ld\n" , usage.ru_nsignals  ); /* signals received              */
    printf ( "\tlong   ru_nvcsw   : %ld\n" , usage.ru_nvcsw     ); /* voluntary context switches    */
    printf ( "\tlong   ru_nivcsw  : %ld\n" , usage.ru_nivcsw    ); /* involuntary context switches  */
}

void Display_exit_signals(int signal){
    printf (".The Description of the exit Signal is: > ");
    if (signal == 0)
        printf ("Signal is 0, then no signal is sent, but error checking is still performed\n");
    if (signal == 1)
        printf ("Signal[SIGHUP]\tVALUE[1]\tACTION[Exit]\tCOMMENT[Hangup]\n");
    if (signal == 2)
        printf ("Signal[SIGINT]\tVALUE[2]\tACTION[Exit]\tCOMMENT[Interrupt]\n");
    if (signal == 3)
        printf ("Signal[SIGQUIT]\tVALUE[3]\tACTION[Core]\tCOMMENT[Quit]\n");
    if (signal == 4)
        printf ("Signal[SIGILL]\tVALUE[4]\tACTION[Core]\tCOMMENT[Illegal Instruction]\n");
    if (signal == 5)
        printf ("Signal[SIGTRAP]\tVALUE[5]\tACTION[Core]\tCOMMENT[Trace/Breakpoint Trap]\n");
    if (signal == 6)
        printf ("Signal[SIGABRT]\tVALUE[6]\tACTION[Core]\tCOMMENT[Abort]\n");
    if (signal == 7)
        printf ("Signal[SIGEMT]\tVALUE[7]\tACTION[Core]\tCOMMENT[Emulation Trap]\n");
    if (signal == 8)
        printf ("Signal[SIGFPE]\tVALUE[8]\tACTION[Core]\tCOMMENT[Arithmetic Exception]\n");
    if (signal == 9)
        printf ("Signal[SIGKILL]\tVALUE[9]\tACTION[Exit]\tCOMMENT[Killed]\n");
    if (signal == 10)
        printf ("Signal[SIGBUS]\tVALUE[10]\tACTION[Core]\tCOMMENT[Bus Error]\n");
    if (signal == 11)
        printf ("Signal[SIGSEGV]\tVALUE[11]\tACTION[Core]\tCOMMENT[Segmentation Fault]\n");
    if (signal == 12)
        printf ("Signal[SIGSYS]\tVALUE[12]\tACTION[Core]\tCOMMENT[Bad System Call]\n");
    if (signal == 13)
        printf ("Signal[SIGPIPE]\tVALUE[13]\tACTION[Exit]\tCOMMENT[Broken Pipe]\n");
    if (signal == 14)
        printf ("Signal[SIGALRM]\tVALUE[14]]\tACTION[Exit]\tCOMMENT[Alarm Clock]\n");
    if (signal == 15)
        printf ("Signal[SIGTERM]\tVALUE[15]\tACTION[Exit]\tCOMMENT[Terminated]\n");
    if (signal == 16)
        printf ("Signal[SIGUSR1]\tVALUE[16]\tACTION[Exit]\tCOMMENT[User Signal 1]\n");
    if (signal == 17)
        printf ("Signal[SIGUSR2]\tVALUE[17]\tACTION[Exit]\tCOMMENT[User Signal 2]\n");
    if (signal == 18)
        printf ("Signal[SIGCHLD]\tVALUE[18]\tACTION[Ignore]\tCOMMENT[Child Status]\n");
    if (signal == 19)
        printf ("Signal[SIGPWR]\tVALUE[19]\tACTION[Ignore]\tCOMMENT[Power Fail/Restart]\n");
    if (signal == 20)
        printf ("Signal[SIGWINCH]\tVALUE[20]\tACTION[Ignore]\tCOMMENT[Window Size Change]\n");
    if (signal == 21)
        printf ("Signal[SIGURG]\tVALUE[21]\tACTION[Ignore]\tCOMMENT[Urgent Socket Condition]\n");
    if (signal == 22)
        printf ("Signal[SIGPOLL]\tVALUE[22]\tACTION[Ignore]\tCOMMENT[Socket I/O Possible]\n");
    if (signal == 23)
        printf ("Signal[SIGSTOP]\tVALUE[23]\tACTION[Stop]\tCOMMENT[Stopped (signal)]\n");
    if (signal == 24)
        printf ("Signal[SIGTSTP]\tVALUE[24]\tACTION[Stop]\tCOMMENT[Stopped (user)]\n");
    if (signal == 25)
        printf ("Signal[SIGCONT]\tVALUE[25]\tACTION[Ignore]\tCOMMENT[Continued]\n");
    if (signal == 26)
        printf ("Signal[SIGTTIN]\tVALUE[26]\tACTION[Stop]\tCOMMENT[Stopped (tty input)]\n");
    if (signal == 27)
        printf ("Signal[SIGTTOU]\tVALUE[27]\tACTION[Stop]\tCOMMENT[Stopped (tty output)]\n");
    if (signal == 28)
        printf ("Signal[SIGVTALRM]\tVALUE[28]\tACTION[Exit]\tCOMMENT[Virtual Timer Expired]\n");
    if (signal == 29)
        printf ("Signal[SIGPROF]\tVALUE[29]\tACTION[Exit]\tCOMMENT[Profiling Timer Expired]\n");
    if (signal == 30)
        printf ("Signal[SIGXCPU]\tVALUE[30]\tACTION[Core]\tCOMMENT[CPU time limit exceeded]\n");
    if (signal == 31)
        printf ("Signal[SIGXFSZ]\tVALUE[31]\tACTION[Core]\tCOMMENT[File size limit exceeded]\n");
    if (signal == 32)
        printf ("Signal[SIGWAITING]\tVALUE[32]\tACTION[Ignore]\tCOMMENT[All LWPs blocked]\n");
    if (signal == 33)
        printf ("Signal[SIGLWP]\tVALUE[33]\tACTION[Ignore]\tCOMMENT[Virtual Interprocessor Interrupt for Threads Library]\n");
    if (signal == 34)
        printf ("Signal[SIGAIO]\tVALUE[34]\tACTION[Ignore]\tCOMMENT[Asynchronous I/O]");
    
}
















