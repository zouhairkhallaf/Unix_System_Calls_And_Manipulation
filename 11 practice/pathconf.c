#include <unistd.h> /* for pathconf()   */
#include <stdio.h>  /* for printf()     */

int main(int argc, char *argv[])
{
    char *filename="/Users/zouhairkhallaf/Desktop/zouzou.txt";
    long max_name_bytes=pathconf(filename, _PC_NAME_MAX);
    
    printf("Name of file %s may have at most %ld bytes.\n", filename, max_name_bytes);
    
    long max_path_bytes=pathconf(filename, _PC_PATH_MAX);
    
    printf("Path of file %s may have at most %ld bytes.\n", filename, max_path_bytes);
    
    return 0;
}