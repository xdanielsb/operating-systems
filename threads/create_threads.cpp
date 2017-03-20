#include <iostream>
#include <stdio.h>
#include <math.h>
#include <pthread.h> /* pthread */
#define SUCCESS 0
#define THREADS 8
#define forn(x) for (int i =0; i< x; i++)
/*
 * Compile and link with -pthread.
 * pthread es una funcion no bloqueante
 * ------------------------------------------ g++ -pthread create_threads.cpp
 */

using namespace std;

void * function (void *ap){
    double val= 0;
    //forn(1000000000)  val += sin(30);
    cout << "hello world, upsi " << *(int*)ap <<endl;
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
    create_threads();
    return 0;
}
