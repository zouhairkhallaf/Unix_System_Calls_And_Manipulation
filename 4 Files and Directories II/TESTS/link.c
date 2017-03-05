#include <unistd.h> /* for link() */
#include <stdio.h>  /* for printf() */
#include <errno.h>  /* for errno() */
#include <string.h> /* for strerror() */

int main(void)
{
    char *file1="/Users/zouhairkhallaf/Desktop/Lecture_5_TESTS/oldlink.txt";
    char *file2="/Users/zouhairkhallaf/Desktop/Lecture_5_TESTS/newlink.txt";
    int n = link(file1, file2);
    
    if (n==0){
        printf("GOOD: The n=%d link funciton was succesful \n", n);
    }else{
        printf("ERROR link returned n=%d UNSUCCESFULLY \n", n);
        
    }
    
    printf("%s\n", strerror(errno));
    return 0;
}