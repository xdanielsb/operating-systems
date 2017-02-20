
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#define WRITE 1
#define READ 0
#define n 10000000
#define four 4.0
//#define _GNU_SOURCE             /* See feature_test_macros(7) */

using namespace std;

typedef long long ll;

inline double father_task(){
    // The father sum the even
    double sum_father= 0.0;
    for (ll i=3; i<(2*n+1); i+=4){
        sum_father += four/i;
        //cout << i << endl;
    }
    return sum_father;
}



inline double son_task(){
    // The son sum the odd 
    double sum_son=0.0;
    for (ll i=1; i<(2*n+1); i+=4){
        sum_son += four/i;
    }
    return sum_son;
}



void pipe(){
    pid_t pid;
 	int pipefd[2];
	int r;
	char mensaje [50];
	double sum_father= 0.0, sum_son=0.0;

	r = pipe(pipefd);
	pid = fork();

    if(pid == 0)  { //Son 

		sum_son = son_task();
		//cout << sum_son << endl;
		close(pipefd[READ]);
		write(pipefd[WRITE], &sum_son, sizeof(double));
		close(pipefd[WRITE]);
    }else if (pid > 0){ //father

		sum_father = father_task();

		close(pipefd[WRITE]);
		read(pipefd[READ], &sum_son, sizeof(double));
		close(pipefd[READ]);

		double r = sum_father-sum_son;
		//cout << sum_father<<endl;
		
		if (r<0) r  = r*-1;
    	printf( "The result is %1.40f\n", r );

		printf("%s", mensaje);
	}else{
		cout << "Opps, there was an error"<< endl;
	}

}
int main(){
    pipe();	
    return 0;
}
