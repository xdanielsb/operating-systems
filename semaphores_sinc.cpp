#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define SUCCESS 0
#define THREADS 8
#define forn(x) for (int i =0; i< x; i++)

#define SNAME "/mysem"


using namespace std;

sem_t *sem;

void * function (void *ap){
    sem_wait(sem);

    double val= 0;
    cout << "hello world, upsi " << *(int*)ap ;
    fflush(stdout);
    sleep(1);
    cout << "ḧello 2 *--- "  << endl;
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
    
    sem = sem_open(SNAME, O_CREAT, 0644,1);

    create_threads();

    sem_close(sem);
    sem_unlink(SNAME);



}
