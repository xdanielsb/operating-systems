#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int main(){
    pid_t pid;
    /* fork a child process */
    pid = fork();

    if (pid < 0){
        perror("Fork Failed");
    }
    else if(pid == 0){
        execlp("/bin/ls", "ls", NULL);
    }else{
        /*Parent will wait for the child to complete */
        wait(NULL);
        cout << "Child complete" << endl;
    }
    
    return 0;
}
