#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t p1;
	int y=0;
	p1=vfork();
	if(p1>0)
	{
		for(int i=0;i<5;i++)
		{
			sleep(i);
			printf("This is parent.Process Id=%d , y=%d\n",getpid(),--y);
		}
	}

	else if(p1==0)
	{
		for(int i=0;i<5;i++)
		{
			sleep(i);
			printf("This is child Process id = %d ,Parent Process id = %d ,y=%d\n",getpid(),getppid(),++y);
		}
		_exit(0);
	}
	else printf("Invalid Process\n");
	return 0;
}
