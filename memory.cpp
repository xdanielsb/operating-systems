#include <iostream>
#include <stdio.h>
#include <sys/ipc.h> //shmget, shmget
#include <sys/shm.h> //shmget, shmget
#include <sys/types.h> //shmat
#include <unistd.h> // pid_t, fork


#define ERROR -1

using namespace std;

int main(){
	char * msj;
	int mem_id; //identificador de la memoria compartida.

	//Parameters for shmeget
	key_t key= 123;
	size_t size=11;

	//Create the memory space
	//0666 the first 0 is for indicate that the number is in base 8
	mem_id = shmget(key, size, 0666|IPC_CREAT);
	if(mem_id == ERROR){
		cerr << "Error in shmget"<<endl;
	}

	//Link memory to process
	msj =(char*) shmat (mem_id,0,0);
	if(msj ==(char*)(ERROR)){
		cerr << "Error en shmat" << endl;
	}

	//Now create the process
	pid_t pid;
	pid = fork();
	string  flag  = "a";
	if(pid == 0){  // This is the son
		sprintf(msj, "Hola Mundo");
		//usleep(1000);
	}else if(pid > 0){ // This is the process´father
		while(msj[0]!= 'H'){
		}
		cout << msj <<endl;
	}else{ // in case of error
		cerr << "Woops, there was an error" << endl;
	}

	//Now desvinculate memory 
	int r = shmdt(msj);


}
