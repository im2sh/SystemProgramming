#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char msg[100]= "";
	int fd1,fd2, nread;
	int result;
	fd1 = open("fifo1", O_RDWR);
	fd2 = open("fifo2", O_WRONLY);
	
	while(1){
		printf("fd1 in Reader = %d\n", fd1);
		nread = read(fd1, msg, 100);
		printf("Reader : %s\n", msg);
		
		printf("\n");	
		strcat(msg, "LeeSeokhwan");

		result = write(fd2,msg,strlen(msg)+1);
		
		if(strcmp(msg,"endLeeSeokhwan") == 0)
			exit(0);
	}
}
