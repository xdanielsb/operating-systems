#include <stdio.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ERROR -1

using namespace std;

int main(){
    int fd, r;
    string aux =  "/tmp/myfifo";
    char * myfifo = (char*)aux.c_str();

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    r = write(fd, "Hi", sizeof("Hi"));
    if(r == ERROR) printf("Woops, there was a problem in write.");
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);
    return 0;
}
