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
    if(1){
    rmess=(char*)shmat(shmid,(void*)0,0);
		printf("[Child:%d]:String received by child:: %s\n\n",getpid(),rmess);
		shmdt(rmess);
		shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}