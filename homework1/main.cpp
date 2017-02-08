#include <iostream>

using namespace std;
/*
 * This program print the size of the variables.
 *  you can compile the program in this way
 *  g++ name_program
 */
int main(){

    cout << "int: "<< sizeof(int) << endl;
    cout << "char: "<< sizeof(char) << endl;
    cout << "unsigned char: "<< sizeof(unsigned char) << endl;
    cout << "double: "<< sizeof(double) << endl;
    cout << "float: "<< sizeof(float) << endl;
    cout << "long: "<< sizeof(long) << endl;
    cout << "usigned long: "<< sizeof(unsigned long) << endl;

    return 0;
}
