#include <iostream>
#include <unistd.h>
#include <stdio.h>

#define n 3000
#define four 4.0
#define sleeptime 1000 //in microseconds

using namespace std;

typedef long long  ll;

FILE *data;

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

inline bool file_exist(){
    data = fopen("data.txt", "r");
    if (data != NULL){
        cout  <<"The file exist" << endl; 
        return true;
    }else {
        cout << "The file does no exist" << endl;
        return false;
    }
    fclose (data);
}

inline void read_file(double calc){
    data = fopen("data.txt", "r");
    double result; 
    fread(&result,sizeof(double),1,data);
    cout << "The data that was readen was " << result << endl;
    cout << "The current data is " << calc << endl;
    printf( "The result is %f\n", calc- result );
    fclose (data);

}

inline void write_file(double result){
    bool exist = file_exist();
    int num_data = 1;
    if (!exist){
        data = fopen("data.txt", "w");
        if (data != NULL){
            cout << "writing in the file " << result << endl;
            fwrite(&result, sizeof(result), num_data, data);
        }else{
            cout << "There was an error writing on the file" << endl;
        }
        fclose (data);
    }else {
        read_file(result);
    
    }
}





int main(){

    pid_t pid = fork();
    double sum_father= 0.0, sum_son=0.0;
    if (pid == 0){ //Child process 

         sum_son = son_task();
         cout << sum_son << endl;
         write_file(sum_son);

    }else if(pid > 0 ) { //Parent process   
         sum_father = father_task();
         cout << sum_father << endl;
         write_file(sum_father);

    }else { // Failed 
        cout << "Woops, There was an error" << endl; 
    }
    return 0;
}
