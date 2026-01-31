#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t p1 = fork();
	if(p1>0)
	{
		sleep(5);
		printf("In Parent\n");
	}
	else if(p1==0)
	{
		printf("In Child\n");
		exit(0);
	}
	return 0;
}
