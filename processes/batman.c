#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t p1;
	if(p1==0)
	{
		sleep(2);
		printf("In child process: %d , of parent id: %d\n",getpid(),getppid());
	}

	else if(p1>0)
	{
		printf("In parent process id: %d\n",getpid());
		exit(0);
	}


	else printf("Process does not exist");
	return 0;
}
