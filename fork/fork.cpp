#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    pid_t pid; 
    pid = fork();
    if (pid == -1){  perror("Whoops, there was a problem creating the process"); exit(1);};
    printf(pid == 0 ? "I am your son, lol\n": "I am your father, darling\n");
}
