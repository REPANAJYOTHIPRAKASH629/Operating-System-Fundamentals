#include <stdio.h>
main()
{
int pid,pid1;
pid=fork();
if(pid==-1)
{
printf(“Error in fork”);
exit(0);
}
if(pid==0)
{
pid1=fork();
exit(0);
}
printf(“\n parent id: %d”,getppid());
printf(“\n Child id : %d”,getpid());
}

/*output*/
parent id: 6535
Child id : 6542




#include<stdio.h>
#include<stdlib.h>

void main()
{
int pid;
pid=fork();
printf("welcome");
if(pid==0)
{
printf("child");
execl("/bin/ls","ls","-l",(char*)0);
printf("hello\n");
}
else
{
wait(0);
printf("parent");
execl("/bin/ls","ls","-f",(char*)0);
}
}


/*output*/
total 597964
drwxr-xr-x 2 root root      4096 Apr 13 12:17 apache2
drwxrwxrwt 1 root root      4096 Apr 13 12:17 lock
drwxr-xr-x 2 root root      4096 Apr 13 12:11 log
drwxr-xr-x 2 root root      4096 Mar  8 02:05 mount
drwxr-xr-x 1 root root      4096 Apr 13 12:19 node_modules
-rwxr-xr-x 1 root root  75175505 Apr 13 12:10 programiz-oc
-rwxr-xr-x 1 root root     35040 Apr 13 12:10 pty.node
drwxr-xr-x 3 root root      4096 May 24 05:06 secrets
drwxr-xr-x 2 root root      4096 Apr 13 12:11 sendsigs.omit.d
lrwxrwxrwx 1 root root         8 Apr 13 12:11 shm -> /dev/shm
drwxr-xr-x 3 root root      4096 Apr 13 12:18 swift-5.7.2-RELEASE-ubuntu22.04
-rw-r--r-- 1 root root 537055150 Apr 13 12:18 swift.tar.gz
drwxr-xr-x 1 root root      4096 Apr 13 12:11 systemd
drwxr-xr-x 2 root root      4096 Apr 13 12:11 user
lock	 mount	       programiz-oc			sendsigs.omit.d
..	 secrets       swift-5.7.2-RELEASE-ubuntu22.04	log
systemd  node_modules  swift.tar.gz			shm
.	 pty.node      apache2				user
