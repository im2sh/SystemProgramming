#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct Node{
	int a;
	float b;
	char name[20];
}Node;

int main(){
	int fd;
	Node data[5];
	int i;
	fd = open("file.bin", O_RDONLY);
	for(i =0;i<5;i++){
		read(fd,&data[i],sizeof(Node));
	}
	for(i=0;i<5;i++){
		printf("[%d] - INT: %d FLOAT: %f STRING: %s\n", i+1, data[i].a,data[i].b,data[i].name);
	}
	close(fd);
}
