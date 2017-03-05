#include <stdio.h> /* for printf() */
#include <signal.h> /* for sigemptyset()... */
#include <string.h> /* for strsignal() */
#include <stdlib.h> /* for malloc() */
#include <unistd.h> /* for alarm() */
void PrintSigset(sigset_t *set);
void handler(int signo);
int main(void)
{
    sigset_t *newset=malloc(sizeof(sigset_t));
    sigset_t *oldset=malloc(sizeof(sigset_t));
    sigset_t *pending=malloc(sizeof(sigset_t));
    
    sigemptyset(newset);
    
    sigaddset(newset, SIGINT);
    sigaddset(newset, SIGHUP);
    
    PrintSigset(newset);
    
    signal(SIGALRM, handler);   /* 1. Signal Alarm is set here */
    sigaddset(newset, SIGALRM); /* 2. Signal is added to the set */
    
    sigprocmask(SIG_BLOCK, newset, oldset); /* 3. signal is blocked here */
    PrintSigset(newset);
    raise(SIGALRM);             /* signal is triggered here */
    
    sleep(3);                   /* signal is delayed here */
    
    sigpending(pending);        /* 4. signal fills in reference arg "pending" */
    if (sigismember(pending, SIGALRM))
        printf("SIGALRM pending\n");
    PrintSigset(pending);       /* 5. signal shown as set member */
    sigprocmask(SIG_SETMASK, oldset, NULL); /* 6. signal is unblocked here */
    PrintSigset(pending);
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
            printf("Received SIGALRM.\n");
            break;
    }
}