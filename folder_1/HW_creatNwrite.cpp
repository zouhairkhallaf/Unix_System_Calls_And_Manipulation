   #include <stdio.h>   // For Creat()
   #include <fcntl.h>   // For Creat()
   #include <unistd.h>  // For Write()
   #include <stdlib.h>  // For Write()
   #include <string>

   #define PERMS 0666     /* Read and Write for owner, group, others // For Creat() */

   int main(int argc, char *argv[]){
      // argv[1] should be the file name. arg[2] name to write in the file
      // int creat(char *name, int perms);  This is how it is defined in #include <fcntl.h>
      //CREATING FILE
      int creat_fd = creat(argv[1], PERMS);
      if (creat_fd == -1)
      { 
        perror("ERROR: Creat()");
        return 1;
      }
      //WRITING TO FILE 
      char* my_name = argv[2];
      std::string  name = argv[2];

      ssize_t nr = write (creat_fd, my_name, sizeof (name));
      if (nr == -1)
      {
        /* ERROR */
        perror("ERROR : Write()");
        return 2;
      }
       return 0;
   }
