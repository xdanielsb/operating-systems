#include <stdio.h>
#include <unistd.h>
int main(){
    int i;
    for (i = 0; i < 4; i++){
        fork();   
    }
    printf("father: %ld, me: %ld\n", (long)getppid(),  (long)getpid());
    
}
