#include<unistd.h>
#include<stdio.h>
int main()
{
	pid_t p1;
	int y=10;
	p1=fork();
	if(p1>0) printf("This is a parent process. Process Id = %d , y = %d\n",getpid(),++y);
	else if(p1==0) printf("This is child Calling Process Id = %d, Parent Process Id = %d, y = %d\n",getpid(),getppid(),--y);
	else printf("Fork Failed");
	return 0;
}
