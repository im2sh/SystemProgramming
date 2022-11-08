#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct node{
	int a;
	float b;
	char name[20];
}Node;

int main(){
	int fd;
	int i;
	Node data[5];
	int x;
	float y;
	int z;

	fd = open("file.bin",O_CREAT|O_RDWR|O_TRUNC, 0666);
	if(fd<0){
		printf("file open failed\n");
		return 0;
	}
	
	for(i = 0; i < 5; i++){
		printf("Enter data[%d]\n",i+1);
		printf("INT:");
		scanf("%d", &data[i].a);
		printf("FLOAT:");
		scanf("%f", &data[i].b);
		printf("STRING:");
		scanf("%s", data[i].name);
		printf("\n");
	}

	for(i = 0; i < 5; i++){
		write(fd, &data[i],sizeof(Node));
	}
	close(fd);
}		
