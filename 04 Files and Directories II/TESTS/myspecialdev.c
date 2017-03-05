#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	int i;
	struct stat buf;
	char *filename = argv[1];
	i = stat(filename, &buf);
	
	if (i<0)
		printf("%s\n", strerror(errno));
	else{
		printf("Major device #: %d\n", major(buf.st_dev));
		printf("Minor device #: %d\n", minor(buf.st_dev));
		
		if (S_ISCHR(buf.st_mode))
			printf("Device %d %d is a character device.\n", major(buf.st_dev), minor(buf.st_dev));
		else if (S_ISBLK(buf.st_mode))
			printf("Device %d %d is a block device.\n", major(buf.st_dev), minor(buf.st_dev));
		else
			printf("Neither.\n");
	}

	return 0;
}
