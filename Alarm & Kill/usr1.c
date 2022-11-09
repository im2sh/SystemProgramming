#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void my_signal(int signum)
{
	printf("SIGUSR2 RECIVED\n");
	exit(0);
}

int main()
{
	pid_t pid;
	pid_t kill_pid;
	pid = getpid();
	printf("pid = %d\n",pid);
	
	printf("Input pid: ");
	scanf("%d",&kill_pid);
	kill(kill_pid, SIGUSR2);
	while(1)
	{
		signal(SIGUSR1,my_signal);
	}

	return 0;
}