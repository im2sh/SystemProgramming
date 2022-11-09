#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void my_sig_handler(int signum)
{
	time_t ct;
	struct tm tm;
	ct = time(NULL);
	tm = *localtime(&ct);
	printf("%d-%d-%d hour:%d, min:%d, sec:%d\n",tm.tm_year + 1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("LEE SEOKHWAN\n");
	count++;
	alarm(5);
}

int main()
{
	int i;
	signal(SIGALRM,my_sig_handler);
	alarm(5);
	while(1){
		sleep(5);
		if(count == 3)
			return 0;
	}

}