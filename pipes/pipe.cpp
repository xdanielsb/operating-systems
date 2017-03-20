
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#define WRITE 1
#define READ 0
//#define _GNU_SOURCE             /* See feature_test_macros(7) */

using namespace std;

void pipe(){
    pid_t pid;
 	int pipefd[2];
	int r;
	char mensaje [50];

	r = pipe(pipefd);
	pid = fork();

    if(pid == 0)  { //Son 
		close(pipefd[READ]);
		write(pipefd[WRITE], "Hello\0", 5);
		close(pipefd[WRITE]);
    }else if (pid > 0){ //father
		close(pipefd[WRITE]);
		read(pipefd[READ], mensaje, 5);
		close(pipefd[READ]);
		printf("%s", mensaje);
	}else{
		cout << "Opps, there was an error"<< endl;
	}

}
int main(){
    pipe();	
    return 0;
}
