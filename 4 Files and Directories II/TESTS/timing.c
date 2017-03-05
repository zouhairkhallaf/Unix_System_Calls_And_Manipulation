#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <time.h> /* for strftime() */
#include <stdio.h>

void FormatTime(time_t rawtime);

int main(int argv, char *argc[]){
	
	int n; /* return value of utime() */
	struct stat statbuf; /* gets filled in when calling stat()*/
	struct utimbuf timebuf; /* either NULL, or specified */
	char *filename="mytiming_file.txt";
	
	stat(filename, &statbuf);
	
	printf("%s: last modification @%ld\n", filename,statbuf.st_mtime);
	printf("%s: last access @%ld\n", filename,statbuf.st_atime);
	printf("%s: last i-node status change@%ld\n", filename, statbuf.st_ctime);
	
	FormatTime(statbuf.st_mtime);
	FormatTime(statbuf.st_atime);
	FormatTime(statbuf.st_ctime);
	
	return 0;
}

void FormatTime(time_t rawtime){
	struct tm *info;
	char buffer[80];
	
	//time(&rawtime); /* sets to current time */
	info=localtime(&rawtime);
	
	//strftime(buffer, 80, "%x - %I:%M%p", info);
	strftime(buffer, 80, "%b %d %H:%M", info);
	printf("Formatted date & time : | %s |\n", buffer);
}
