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
	char recv_buf[100];

	key = 1234;
	msgqid = msgget(key,IPC_CREAT|0666);
	printf("msgqpid = %d \n", msgqid);
	while(1){
		printf("Enter a string to send: ");
		gets(buf);
		msgsnd(msgqid,buf,strlen(buf)+1,0);

		memset(buf,0,strlen(buf));
		msgrcv(msgqid,recv_buf,100,0,0);
		printf("Received msg = %s\n\n", recv_buf);
		if(!strcmp(recv_buf, "endLeeSeokhwan"))
			exit(0);

		memset(buf,0,strlen(buf));
		memset(recv_buf,0,strlen(recv_buf));
	}
}
