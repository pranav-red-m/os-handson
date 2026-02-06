#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFFER_SIZE 100

int main()
{
    int fd1;
    char buff[BUFFER_SIZE]="";
    char myfifo[BUFFER_SIZE] = "/tmp/myfifo"; //myfifo is the name of the file
    mkfifo(myfifo,0666); //0666 hard coded read and write permissiosn for onwwer group others
    fd1 = open(myfifo,O_RDONLY);
    read(fd1,buff,BUFFER_SIZE);
    printf("Information read: %s",buff);
    close(fd1);
    return 0;
}