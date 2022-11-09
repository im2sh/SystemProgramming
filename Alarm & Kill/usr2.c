#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void my_signal()
{
	int pid;
	printf("SIGNAL1 RECIVED!\n");
	printf("Input pid:");
	scanf("%d",&pid);
	kill(pid, SIGUSR1);
	exit(0);
}


int main()
{
	pid_t pid;
	pid = getpid();
	printf("pid = %d \n",pid);

	while(1)
	{
		signal(SIGUSR2, my_signal);
	}
	return 0;
}