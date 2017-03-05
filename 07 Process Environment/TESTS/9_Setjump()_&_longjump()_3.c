#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
typedef struct
{
    int command;
    int data;
    int isbusy;
} myGadget;
//void SendCommand(volatile myGadget *g, int command, int data);
void SendCommand(myGadget *g, int command, int data);
static jmp_buf array;
int main(void)
{
    //volatile static myGadget gadget;
    static myGadget gadget;
    gadget.isbusy=0;
    SendCommand(&gadget, 1, 2);
    if (setjmp(array)!=0) //0 if called directly
    {
        printf("After longjmp(): %d\t%d\t%d\n",
               gadget.command, gadget.data, gadget.isbusy);
        exit(0);
    }
    else
    {
        SendCommand(&gadget, 4, 5);
        printf("Before longjmp(): %d\t%d\t%d\n",
               gadget.command, gadget.data, gadget.isbusy);
        longjmp(array, 1);
    }
    return 0;
}
//void SendCommand(volatile myGadget *g, int command, int data)
void SendCommand(myGadget *g, int command, int data)
{
    while (g->isbusy)
    {}
    g->data=data;
    g->command=command;
}