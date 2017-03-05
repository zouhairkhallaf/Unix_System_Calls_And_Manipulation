#include <stdio.h>
#include <signal.h>
#include <string.h>
void PrintSigset(sigset_t *set);
int main(void)
{
    sigset_t set;
    sigfillset(&set);
    PrintSigset(&set);
}
void PrintSigset(sigset_t *set)
{
    for (int i=1; i<32; i++)
    {
        if (sigismember(set, i))
            printf("Signal %d: %s\n", i, strsignal(i));
    }
}