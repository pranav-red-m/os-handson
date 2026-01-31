#include<unistd.h>
#include<stdio.h>
int main()
{
	pid_t p1;
	p1=fork();
	if(p1<0) printf("Fork failed\n");
	else if(p1==0) printf("Child Process\n");
	else printf("Parent Process\n");
	return 0;
}
