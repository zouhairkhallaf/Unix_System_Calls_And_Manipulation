#include <stdio.h> /* for printf() */
#include <signal.h> /* for sigemptyset()... */
#include <string.h> /* for strsignal() */
#include <stdlib.h> /* for malloc() */
void PrintSigset(sigset_t *newest);
void handler(int signo);


volatile sig_atomic_t usr_interrupt = 0;

void intHandler(int dummy) {
    usr_interrupt = 1;
}

int main(void)
{
    printf("\n\n");

    sigset_t *newest=malloc(sizeof(sigset_t));
    sigset_t *oldest=malloc(sizeof(sigset_t));
    sigset_t *waitest=malloc(sizeof(sigset_t));
    
    printf(".EMPTY ALL SIGNAL CONTAINERS:\n");
    printf("\t- Expect: newest ={}\n");
        sigemptyset(newest);
        PrintSigset(newest);
    printf("\t- Expect: oldest ={}\n");
        sigemptyset(oldest);
        PrintSigset(oldest);
    printf("\t- Expect: waitest={}\n");
        sigemptyset(waitest);
        PrintSigset(waitest);
    
    printf("\n.ADD 3 signals Expect: newest= {SIGSYS,SIGHUP,SIGALRM}\n");
        sigaddset(newest, SIGSYS);
        sigaddset(newest, SIGHUP);
        sigaddset(newest, SIGALRM);
        PrintSigset(newest);
    
    printf("\n.ADD 1 signal Expect: oldest={SIGINT}\n");
        sigaddset(oldest, SIGINT);
        PrintSigset(oldest);

    printf("\n.sigprocmask() with :\n");
    printf("\t 1. SIG_BLOCK: Adds a signal to the BLOCKED signals\n\n");
    printf("\t\t Expect newest={1,12,14} to be BLOCKED  \n\n");
            sigprocmask(SIG_BLOCK, newest, oldest);
    
    printf("\t\t signals (1, 12 and 14) are set with handelers)\n\n");
            signal(SIGSYS, handler);  /* 1. send SIGINT */
            signal(SIGHUP, handler);  /* 2. send SIGHUP */
            signal(SIGALRM, handler); /* 3. send SIGALRM */
    printf("\t\t Trigger 3 signals SIGSYS=12, SIGHUP=1, and SIGALRM=14\n\n");
            raise(SIGSYS);  /* signal is triggered here */
            raise(SIGHUP);
            raise(SIGALRM); /* signal is triggered here */
    printf("\t\t Fill the Blocked signals container EXPECT: {SIGINT=2 and SIGALARM=14},\n\n");
            sigpending(waitest); /* 4. signal fills in reference arg "waitest" */
            if (sigismember(waitest, SIGSYS))
                    printf("\t\t\t-> SIGSYS  is member SIGNAL in waitest\n");
            if (sigismember(waitest, SIGHUP))
                    printf("\t\t\t-> SIGHUP  is member SIGNAL in waitest\n");
            if (sigismember(waitest, SIGALRM))
                    printf("\t\t\t-> SIGALRM is member SIGNAL in waitest\n");
            PrintSigset(waitest);
    
    /*
    printf("\n\n");
    printf("**ATT: SIGSUSPEND CALLED ON OLDEST MASK\n");
    //Wait for a signal to arrive.
    while (!usr_interrupt){
        printf("**ATT: ENTER CTRL+C TO TRIGGER SIGINT \n");
        signal(SIGINT, intHandler);
        sigsuspend(oldest);
    }
    sigprocmask(SIG_UNBLOCK, oldest, NULL); //signal is unblocked here
    printf("\t- Expect: oldest ={}\n");
    PrintSigset(oldest);
    */
    

    printf("\n\n");

}
void PrintSigset(sigset_t *newest)
{
    printf("\t\t---------PRINTING CONTAINER---------\n");
    for (int i=1; i<32; i++)
    {
        if (sigismember(newest, i))
            printf("\t\tSignal %d: %s\n", i, strsignal(i));
    }
    printf("\t\t-----------PRINTING ENDS----------\n");
}

void handler(int signo)
{
    switch (signo)
    {
        case SIGINT:
            printf("\t\t--> SIGINT Unblocked and Received: %d \n", signo);
            break;
        case SIGHUP:
            printf("\t\t--> SIGHUP Unblocked and Received: %d \n", signo);
            break;
        case SIGALRM:
            printf("\t\t--> SIGALRM Unblocked and Received: %d \n", signo);
            break;
        default:
            printf("\t\t--> ERROR: THIS SIGNAL IS UNDEFINED: %d \n", signo);
    }
}
