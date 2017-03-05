#include <unistd.h> /* for link() */
#include <stdio.h> /* for printf() */
#include <errno.h> /* for errno() */
#include <string.h> /* for strerror() */
int main(void)
{
char *newpath="/Users/zouhairkhallaf/Desktop/Lecture_5_TESTS/newlink.txt";
int n=unlink(newpath);
printf("File %s unlinked.\n", newpath);
sleep(15);
printf("Program done.\n");
printf("n=%d\n", n);
printf("%s\n", strerror(errno));
return 0;
}
