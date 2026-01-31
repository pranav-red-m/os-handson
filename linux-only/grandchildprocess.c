#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t p1,p2;
	int y=0;
	p1=fork();
	if(p1>0)
	{
		wait(NULL);
		printf("This is parent. Process Id = %d, y=%d\n",getpid(),--y);
	}

	if(p1==0)
	{
		p2 = fork();
		if(p2>0) wait(NULL);
		else if(p2==0)
		{
			y+=5;
			printf("This is grandchild process. Process Id = %d , Parent Process Id = %d , y = %d\n",getpid(),getppid(),y);
			exit(0);
		}
		printf("This is Child Process. Process Id = %d , Parent Process Id = %d , y = %d\n",getpid(),getppid(),++y);
	}

	else printf("Fork creation Failed");
	return 0;
}
