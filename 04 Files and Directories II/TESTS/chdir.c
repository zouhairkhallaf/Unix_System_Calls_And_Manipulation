#include <unistd.h> /* for chdir() */
#include <stdio.h> /* for printf() */
#include <errno.h> /* for errno */
#include <string.h> /* for strerror() */
#include <stdlib.h> /* for malloc() */
#include <fcntl.h> /* for open() */
int main(void){
	char *filename = "/Users/zouhairkhallaf/Desktop/Just_for_testing";
	char *buf;	 /* address of buffer holding new pathname */
	int size; 	 /* size allocated for pathname */
	char *ptr; 	 /* return value from getcwd() */
	int fd;		 /* file descriptor of the file created in the new dir */
	size=1024;
	
	buf=malloc(size);

	printf ("%s\n", filename);
	
	int i = chdir(filename);
	
	if (i==-1)
		printf("%s\n", strerror(errno));
	else
		printf("Directory was changed to %s.\n", filename);

	ptr = getcwd(buf, size);
	
	if (ptr==NULL)
		printf("%s\n", strerror(errno));
	else
		printf(" CWD = %s\n", ptr);

	char *newfile ="/foo";
	
	strcat(ptr, newfile);
	
	fd = open(ptr, O_RDWR|O_CREAT|O_TRUNC);
	
	printf("File descriptor for file %s is %d\n", ptr, fd);

return 0;
}
