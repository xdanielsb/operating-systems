#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024


using namespace std;

int main(){
    int fd;
    string aux =  "/tmp/myfifo";
    char * myfifo = (char*)aux.c_str(); 
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    do {

        fd = open(myfifo, O_RDONLY);
        if (fd == -1) sleep (1);

    }while(fd == -1);

    read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);
    close(fd);

    return 0;
}
