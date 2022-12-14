
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define MAX_SIZE 100

int main()
{
    key_t key;
    sem_t *sem_write, *sem_read;
    int shmid;
    char *shmaddr;
    char buf[MAX_SIZE];

    sem_write = sem_open("BtoA", O_CREAT, 0666, 0);
    sem_read = sem_open("AtoB", O_CREAT, 0666, 0);
    key = 100;
    shmid = shmget(key,sizeof(int),IPC_CREAT | 0666);
    shmaddr = shmat(shmid,NULL, 0);
    printf("sem_write = %p\n", sem_write);
    printf("sem_read = %p\n", sem_read);
    printf("shmid = %d\n\n",shmid);
    
    while(1){
        sem_wait(sem_read);
        strcpy(buf,shmaddr);
        printf("Received msg = %s\n",buf);
        
        sleep(1);

        strcat(buf,"Leeseokhwan");
        printf("Sending msg : %s\n\n",buf);
        strcpy(shmaddr,buf);
        sem_post(sem_write);
        if(!strcmp(buf,"endLeeseokhwan"))
            exit(0);
        memset(buf,0,strlen(buf));
    }
    shmctl(shmid, IPC_RMID,0);
    
    return 0;
}
