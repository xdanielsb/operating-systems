#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_PROCESOS 1
#define NUM_HILOS 8

struct datos_tipo{
    int dato;
    int p;
};

void* proceso(void* datos){

    datos_tipo* datos_proceso;
    datos_proceso = (struct datos_tipo*)datos;
    int a, i, j, p;

    a = datos_proceso->dato;
    p = datos_proceso->p;

    for (i = 0; i <= p; i++){
        printf(" %i ", a);
    }
    fflush(stdout);
    sleep(1);
    for (i = 0; i <= p; i++){
        printf("- ");
    }
    fflush(stdout);
}

int main(){
    int error, i;
    char* valor_devuelto;
    struct datos_tipo hilo_datos[NUM_HILOS];
    pthread_t idhilo[NUM_HILOS];
    for (i = 0; i < NUM_HILOS; i++) {
        hilo_datos[i].dato = i;
        hilo_datos[i].p = i + 1;
    }
    for (i = 0; i < NUM_HILOS; i++){
        error = pthread_create(&idhilo[i], NULL, proceso, (void*)(&hilo_datos[i]));
        if (error != 0){
            perror("No puedo crear hilo");
            exit(-1);
        }
    }

    for (i = 0; i < NUM_HILOS; i++){
        pthread_join(idhilo[i], (void**) & valor_devuelto);
    }
    return 0;
}
