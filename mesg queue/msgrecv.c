#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int msgqid;
	key_t key;
	char buf[100];

	key = 1234;
	msgqid = msgget(key,IPC_CREAT|0666);
	printf("msgqpid = %d \n", msgqid);
	while(1){
		msgrcv(msgqid,buf,100,0,0);
		printf("msg = %s\n", buf);

		strcat(buf, "LeeSeokhwan");
		msgsnd(msgqid,buf,strlen(buf)+1,0);
		if(!strcmp(buf,"endLeeSeokhwan"))
			exit(0);
		memset(buf,0,strlen(buf));
		
	}
}

