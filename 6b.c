#include <stdio.h>
int main()
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
#include<sys/wait.h>
int main()
{
int pid;
printf("welcome\n");
pid=fork();


if(pid==0)
{
printf("child :%d\n",getpid());
printf("%d",getpid());
execl("/bin/ls","ls",(char*)0);


}
else
{
wait(NULL);
printf("parent :%d\n",getpid());
execl("/bin/ls","ls","-f",(char*)0);

}
return 0;
}



/*output*/

[22695a3203@GDLC 22695A3203]$ cc 6c.c
[22695a3203@GDLC 22695A3203]$ ./a.out
welcome
child :114290
\       2b,sh  6c     evenodd.sh    hell01.java  multipleopens.sh  permission.sh    priority.c.save.1  sample.txt  two.java                world.py
1       2b.sh  6c.c   factorial.sh  hello1.java  new               power.sh         rr.c               sjf.c       twoo.sh
10.c    6a.c   a.out  fcfs.c        hello.c      one.class         priority.c       salary.sh          s.txt       uppercase_filenames.sh
123.sh  6b.c   env.c  filenames.sh  help.sh      one.sh            priority.c.save  sample1.txt        two.class   world1.py
parent :114289
factorial.sh  \            permission.sh  6b.c         sample1.txt  priority.c  filenames.sh  multipleopens.sh        one.sh             6c
2b,sh         fcfs.c       2b.sh          1            one.class    6a.c        123.sh        .priority.c.swp         priority.c.save    salary.sh
.6a.c.swp     hell01.java  twoo.sh        .6a.c.swo    new          evenodd.sh  env.c         uppercase_filenames.sh  a.out
6c.c          two.java     power.sh       hello1.java  rr.c         sjf.c       10.c          help.sh                 priority.c.save.1
sample.txt    .            ..             hello.c      .rr.c.swp    world1.py   s.txt         world.py                two.class


