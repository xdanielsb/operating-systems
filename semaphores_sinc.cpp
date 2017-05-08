#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define SUCCESS 0
#define THREADS 3
#define NUM_CLIENTS_SAME_TIME 1
#define forn(x) for (int i =0; i< x; i++)

#define SNAME "/mysem2"

/*
 *  Run with the flag -pthread
 */ 

using namespace std;

sem_t *sem;

void * function (void *ap){
    sem_wait(sem);

    double val= 0;
    int code =  *(int*)ap ;
    cout << "hello world, upsi " << code << " ";
    fflush(stdout);
    sleep(1);
    cout << "ḧello  *--- "  << endl;

    sem_post(sem);

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


int main (){
    
    sem = sem_open(SNAME, O_CREAT, 0644, NUM_CLIENTS_SAME_TIME );

    create_threads();

    sem_close(sem);
    sem_unlink(SNAME);



}
