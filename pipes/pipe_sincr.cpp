#include <fcntl.h>             
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <pthread.h> /* pthread */

#define SUCCESS 0
#define THREADS 8

#define WRITE 1
#define READ 0


using namespace std;

int pipefd[2];
int r;
char mensaje [50];

void * function (void *ap){
    
    write(pipefd[WRITE], "Hello\0", 5);

    double val= 0;
    cout << "hello world, upsi " << *(int*)ap ;
    fflush(stdout);
    sleep(1);
    cout << "ḧello 2 *--- "  << endl;

    read(pipefd[READ], mensaje, 5);

}

void create_threads(){
    pthread_t hilo[THREADS];
    int *values = new int[THREADS];
    for (int i=1; i<=THREADS; i++)
        values[i-1] = i;

    int result;
    int arg =1,c; /*  c -> control variable */

     for (int i =0; i< THREADS; i++)
         result = pthread_create(&hilo[i], NULL,  function, (void*) &values[i]);
     for (int i =0; i< THREADS; i++)
        result = pthread_join (hilo[i], NULL); //Wait until the threads finish
}



int main(){
    
	r = pipe(pipefd);
    if(r == 0) perror("Error creating pipe");
	create_threads();
    return 0;
}
