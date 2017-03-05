/*
USET THIS COMMAND BEFORE AND AFTER RUNNING THIS PROGRM TO SEE THE DIFFERENCE OF SPACE USED END THEN RELEASESD
$ df ~zouhairkhallaf/Desktop/Lecture_5_TESTS/
*/



#include <unistd.h> /* for link() */
#include <stdio.h> /* for printf() */
#include <errno.h> /* for errno() */
#include <string.h> /* for strerror() */
int main(void)
{
char *newpath="/Users/zouhairkhallaf/Desktop/Lecture_5_TESTS/oldlink.txt";
int n=unlink(newpath);
printf("n=%d\n", n);
printf("%s\n", strerror(errno));
return 0;
}
