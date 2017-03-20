#include <iostream>
#include <stdio.h>
#include <sys/ipc.h> //shmget, shmget
#include <sys/shm.h> //shmget, shmget
#include <sys/types.h> //shmat
#include <unistd.h> // pid_t, fork
#include <iostream>

#define four 4.0
#define n 3000
#define LOC 123
#define ERROR -1

using namespace std;

int *flag;

void des(double *msj){
	int r = shmdt(msj);
}

double * create_memory(){
	double * msj;
	int mem_id; //identificador de la memoria compartida.

	//Parameters for shmeget
	key_t key= LOC;
	size_t size=sizeof(double*);

	//Create the memory space
	//0666 the first 0 is for indicate that the number is in base 8
	mem_id = shmget(key, size, 0666|IPC_CREAT);
	if(mem_id == ERROR){
		cerr << "Error in shmget"<<endl;
	}
	
	//Link memory to process
	msj =(double*) shmat (mem_id,0,0);
	flag = (int*) (msj + sizeof(double*));
	
	return msj;
}


inline double positive_task(){
    // The son sum the odd 
    double sum_son=0.0;
    for (long long i=1; i<(2*n+1); i+=4){
        sum_son += four/i;
    }
    return sum_son;
}


int main(){

	double * v = new double[1];
	double val  = positive_task();
 
	cout << v[0] << endl;
	double * msj = create_memory();

	while (flag != 0){
		flag = (int*) (msj + sizeof(double*));
	}

	v[0] = msj;

	//Des
	des(msj);

	return 0;
}

