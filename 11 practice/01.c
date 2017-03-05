#include <stdio.h>
#include <signal.h>
#include <string.h>
void PrintSigset(sigset_t *set);
int main(void)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGHUP);
    sigaddset(&set, SIGALRM);
    PrintSigset(&set);
}
void PrintSigset(sigset_t *set)
{
    if (sigismember(set, SIGINT))
        printf("Signal SIGINT added to the set.\n");
    if (sigismember(set, SIGHUP))
        printf("Signal SIGHUP added to the set.\n");
    if (sigismember(set, SIGALRM))
        printf("Signal SIGALRM added to the set.\n");
    for (int i=1; i<32; i++)
    {
        if (sigismember(set, i))
            printf("Signal %d: %s\n", i, strsignal(i));
    }
}