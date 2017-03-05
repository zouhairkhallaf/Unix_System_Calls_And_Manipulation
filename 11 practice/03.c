#include <stdio.h> /* for printf() */
#include <signal.h> /* for sigemptyset()... */
#include <string.h> /* for strsignal() */
#include <stdlib.h> /* for malloc() */
void PrintSigset(sigset_t *set);
int main(void)
{
    sigset_t *set=malloc(sizeof(sigset_t));
    sigset_t *oset=malloc(sizeof(sigset_t));
    
    sigemptyset(set); //To empty the set
    
    sigaddset(set, SIGINT); // Adds sig number 1
    sigaddset(set, SIGHUP); // Adds sig number 2
    
    PrintSigset(set);       // See the function definition bellow
    
    sigaddset(set, SIGALRM);// Adds 3 SIGALARM (remember there are )
    sigprocmask(SIG_SETMASK, set, oset); // sigprocmask(SIG_SETMASK|SIG_BLOCK|SIG_UNBLOCK, set, oset)
    PrintSigset(set);
    
    printf ("\nI AM PRINTING: oset\n");
    PrintSigset(oset);
    
}
void PrintSigset(sigset_t *set)
{
    printf("-----------------------------\n");
    for (int i=1; i<32; i++)
    {
        if (sigismember(set, i))//loop through the entire members of the set
            printf("Signal %d: %s\n", i, strsignal(i));//strsignal: reads the sig message
    }
    printf("-----------------------------\n");
}