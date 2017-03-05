#include <stdio.h> /* for printf() */
#include <signal.h> /* for sigemptyset()... */
#include <string.h> /* for strsignal() */
#include <stdlib.h> /* for malloc() */
#include <unistd.h> /* for alarm() */
void PrintSigset(sigset_t *set);
void handler(int signo);
sigset_t *newset, *oldset, *pending, *blocked;
int main(void)
{
    blocked=malloc(sizeof(sigset_t));
    sigemptyset(blocked);
    sigaddset(blocked, SIGINT);
    sigaddset(blocked, SIGHUP);
    struct sigaction *act=malloc(sizeof(sigaction));
    struct sigaction *oact=malloc(sizeof(sigaction));
    act->sa_handler=handler;
    act->sa_mask=*blocked;
    act->sa_flags=SA_RESTART;
    newset=malloc(sizeof(sigset_t));
    oldset=malloc(sizeof(sigset_t));
    pending=malloc(sizeof(sigset_t));
    sigemptyset(newset);
    sigaddset(newset, SIGINT);
    sigaddset(newset, SIGHUP);
    sigaction(SIGALRM, act, oact); /* signal is set here */
    sigaddset(newset, SIGALRM); /* signal is added here */
    printf("After adding SIGALRM...\n");
    PrintSigset(newset);
    raise(SIGALRM); /* signal is triggered here */
    raise(SIGINT);
    //sleep(3);
    sigpending(pending); /* SIGALRM fills in reference arg
                          "pending" w. blocked signals from handler() */
    if (sigismember(pending, SIGINT) && sigismember(pending,
                                                    SIGHUP))
        printf("SIGINT and SIGHUP pending.\n");
    printf("Signals pending:\n");
    PrintSigset(pending); /* pending signals are shown as
                           members of set "pending" */
    alarm(0);
    /*
     sigprocmask(SIG_SETMASK, oldset, NULL);
     PrintSigset(newset);
     sigdelset(newset, SIGALRM);
     PrintSigset(newset);
     */
}
void PrintSigset(sigset_t *set)
{
    printf("-----------------------------\n");
    for (int i=1; i<32; i++)
    {
        if (sigismember(set, i))
            printf("Signal %d: %s\n", i, strsignal(i));

    }
    printf("-----------------------------\n");
}
void handler(int signo)
{
    switch (signo)
    {
        case SIGALRM:
            printf("In handler()...\n");
            printf("Received SIGALRM.\n");
            sigprocmask(SIG_BLOCK, blocked, oldset); /* all other
                                                      signals are blocked here */
            printf("Signals blocked by SIGALRM's handler():\n");
            PrintSigset(blocked);
            sleep(3);
            break;
    }
}