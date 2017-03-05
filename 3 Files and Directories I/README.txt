 
TO RUN PROGRAM “Zouhair_Khallaf_HW_3_PART_I_chown.c” FOR PART I

 2 things are necessary to run this code and see the effect.
 
 1. FIRST: The computer must have at least a second users (other than admin).
    to create a new user in MAC:
                1.Choose Apple menu > System Preferences, then click Users & Groups.
                2.Click the lock icon to unlock it, then enter an administrator name and password.
                3.Click the Add button below the list of users (it's a plus + sign).
                4.Enter the Full Name, Account Name, and (Use separate password) password of the new user, then Create User
                5.Click Create a User, Close this window and go to terminal.
 
 2. SECOND : The User must become a superuser before this code can run otherwise the permission will be denied
     In the terminal:
                Do      : $ touch some_test_file.txt
                Do      : $ ls -l some_test_file.txt
                see     : $ (now you can see the owner in the resuts)
                Use     : $ sudo -s
                pwd     : $ ******* (password)
                Then    : $ cd to/path/where/this/program/is/located
                run     : $ gcc <name_of_prog.c> -o <name_of_prog> (to compile)
                and     : $ ./name_of_prog   <new_user_name>    <some_test_file.txt> (to run)
                check   : $ ls -l some_test_file.txt (to check the effect)
                see     : $ (now you can see the NEW OWNER in the resuts instead of OLD OWNER) (Well done!)
 
 This program was tested.