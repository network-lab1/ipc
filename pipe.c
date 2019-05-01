#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 
  int pipes[2];
  char str[20],s[20];
  pid_t p;
  if(pipe(pipes)== -1)
  {
   printf("piping failed");
   return 1;
  }
  p=fork();
  if(p<0)
  {
    printf("fork failed");
    return 1;
   }
  if(p>0)
  {
    printf("string %d[child]",getpid());
    gets(str);
    close(pipes[0]);
    write(pipes[1],str,strlen(str));
    close(pipes[1]);
  }
  else   
  {
    close(pipes[1]);
    read(pipes[0],s,30);
    close(pipes[0]);
    printf("string got in %d[parent] %s",getpid(),s);
    return 0;
   }
}