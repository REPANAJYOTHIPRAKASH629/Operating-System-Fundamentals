#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int c,char **args)
{
    char path[100];
    struct stat fileStat;
    int i;

    if(c==1)
    {
       printf("Enter the file names to check\n");
       return 0;
    }


    for(i=1;i<=c;i++)
    {
    if (stat(args[i], &fileStat) < 0) {
        printf("Error: Failed to get file/directory status.\n");
        return 1;
    }


    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file.\n", args[i]);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory.\n", args[i]);
    } else {
        printf("%s is neither a file nor a directory.\n", args[i]);
    }


    printf("Permissions:\n");
    printf("Read permission: %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write permission: %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute permission: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
    }
    return 0;
}



/* output 

[22695a3203@GDLC 22695A3203]$ cc 10.c
[22695a3203@GDLC 22695A3203]$ ./a.out 6b.c
6b.c is a regular file.
Permissions:
Read permission: Yes
Write permission: Yes
Execute permission: No
Error: Failed to get file/directory status.
[22695a3203@GDLC 22695A3203]$

*/

