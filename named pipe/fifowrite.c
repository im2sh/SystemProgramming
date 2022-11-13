#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1, fd2, nread;
	char msg[100];

	fd1 = open("fifo1", O_WRONLY);
	fd2 = open("fifo2", O_RDWR);

	while(1){
		printf("fd1 in Writer = %d\n", fd1);
		printf("Enter a string to send : ");
		gets(msg);
		
		write(fd1,msg,strlen(msg)+1);
	
		memset(msg, 0, strlen(msg));

		printf("fd2 in Reader = %d\n", fd2);
		nread = read(fd2,msg,100);
		if(!strcmp(msg,"endLeeSeokhwan"))
			exit(0);

		printf("Received Msg : %s\n",msg);
		printf("\n");

	}
}
