#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	printf("Using execv() to execute 'hello':\n");
	char*args[]={"hello",NULL};
	if(fork()==0)
	{
		execv("./hello",args);
		perror("execv failed");
		exit(1);
	}
	wait(NULL);
	printf("execv() example\n");
	return 0;
}
