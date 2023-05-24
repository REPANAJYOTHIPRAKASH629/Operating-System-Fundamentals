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
#include<unistd.h>
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
execl("/bin/ls","ls","-l",(char*)0);
}
}


/*output*/

total 1388
-rw-rw-r-- 1 22695a3203 22695a3203       0 Apr  1 10:15 1
-rw-rw-r-- 1 22695a3203 22695a3203 1286144 Apr  1 10:13 123.sh
-rw-rw-r-- 1 22695a3203 22695a3203       0 Apr 12 11:02 2b,sh
-rw-rw-r-- 1 22695a3203 22695a3203     123 Apr 12 11:37 2b.sh
-rw-rw-r-- 1 22695a3203 22695a3203     254 May 24 11:17 6a.c
-rwxrwxr-x 1 22695a3203 22695a3203    7081 May 24 11:17 a.out
-rw-rw-r-- 1 22695a3203 22695a3203     217 May 24 10:32 env.c
-rw-rw-r-- 1 22695a3203 22695a3203     101 Apr  1 09:52 evenodd.sh
-rw-rw-r-- 1 22695a3203 22695a3203     120 Apr  1 10:15 factorial.sh
-rw-rw-r-- 1 22695a3203 22695a3203     810 May 10 11:14 fcfs.c
-rw-rw-r-- 1 22695a3203 22695a3203     923 Apr 12 11:50 filenames.sh
-rw-rw-r-- 1 22695a3203 22695a3203       0 Mar 29 10:43 hell01.java
-rw-rw-r-- 1 22695a3203 22695a3203     116 Mar 29 10:46 hello1.java
-rw-rw-r-- 1 22695a3203 22695a3203      84 Apr 12 11:21 hello.c
-rw-rw-r-- 1 22695a3203 22695a3203      93 Apr  1 10:51 help.sh
-rw-rw-r-- 1 22695a3203 22695a3203     261 May  2 11:46 multipleopens.sh
drwxrwxr-x 2 22695a3203 22695a3203    4096 Apr 12 11:04 new
-rw-rw-r-- 1 22695a3203 22695a3203     414 Mar 29 10:46 one.class
-rw-rw-r-- 1 22695a3203 22695a3203     127 Mar 29 11:57 one.sh
-rw-rw-r-- 1 22695a3203 22695a3203     215 May  3 09:50 permission.sh
-rw-rw-r-- 1 22695a3203 22695a3203      84 Apr  1 12:03 power.sh
-rw-rw-r-- 1 22695a3203 22695a3203    2344 May 10 11:14 priority.c
-rw------- 1 22695a3203 22695a3203    2341 May 10 12:07 priority.c.save
-rw------- 1 22695a3203 22695a3203    2341 May 10 12:07 priority.c.save.1
-rw-rw-r-- 1 22695a3203 22695a3203    1084 May 24 10:09 rr.c
-rw-rw-r-- 1 22695a3203 22695a3203     316 Apr 12 11:58 salary.sh
-rw-rw-r-- 1 22695a3203 22695a3203      25 May  2 11:48 sample1.txt
-rw-rw-r-- 1 22695a3203 22695a3203       0 Apr 12 09:55 sample.txt
-rw-rw-r-- 1 22695a3203 22695a3203    1237 May 10 10:42 sjf.c
-rw-rw-r-- 1 22695a3203 22695a3203      44 Apr  1 09:23 s.txt
-rw-rw-r-- 1 22695a3203 22695a3203     411 Mar 29 10:54 two.class
-rw-rw-r-- 1 22695a3203 22695a3203     118 Mar 29 10:53 two.java
-rw-rw-r-- 1 22695a3203 22695a3203     101 Apr  1 09:51 twoo.sh
-rw-rw-r-- 1 22695a3203 22695a3203     208 Apr 12 10:00 uppercase_filenames.sh
-rw-rw-r-- 1 22695a3203 22695a3203      22 Mar 29 11:42 world1.py
-rw-rw-r-- 1 22695a3203 22695a3203      10 Mar 29 11:45 world.py
factorial.sh  fcfs.c       permission.sh  ..           hello.c      rr.c        evenodd.sh    123.sh            .priority.c.swp         one.sh             two.class
2b,sh         hell01.java  2b.sh          1            sample1.txt  .rr.c.swp   sjf.c         env.c             uppercase_filenames.sh  priority.c.save    salary.sh
.6a.c.swp     two.java     twoo.sh        .6a.c.swo    one.class    priority.c  world1.py     s.txt             help.sh                 a.out
sample.txt    .            power.sh       hello1.java  new          6a.c        filenames.sh  multipleopens.sh  world.py                priority.c.save.1

