#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFFER_SIZE 25
int main()
{
    int fd;
    char buff[BUFFER_SIZE] = "";
    char myfifo[BUFFER_SIZE] = "/tmp/myfifo";
    printf("Enter msg to be passed:\n");
    read(0,buff,BUFFER_SIZE);
    mkfifo(myfifo,0666);
    fd = open(myfifo,O_WRONLY);
    write(fd,buff,strlen(buff)+1);
    close(fd);
    return 1;
}