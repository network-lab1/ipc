#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
int main(){
	key_t key;
	int shmid;
	char *smess,*rmess;
	key=ftok("msgq",45);
	shmid=shmget(key,1024,0666 | IPC_CREAT);
	if(1)
    {
		smess=(char*)shmat(shmid,(void*)0,0);
		printf("[Parent:%d]:Enter string to add to shared memory::",getpid());
		gets(smess);
		shmdt(smess);			
	}
    return 0;
}