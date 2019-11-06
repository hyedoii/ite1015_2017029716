#include <iostream>
#include <stdio.h>

using namespace std;

int i, j;
int* arr;

string primeFactorization(unsigned int_number){
    int i = 2, j = 0, k = 0, n = 0;
    char arr[100] = {""};
    for(i=2;i<=int_number;i++){
        n = 0;
        if(int_number % i ==0){
            arr[k] = i + 48;
            k++;
            arr[k] = '^';
            k++;
            for(j=0;j<int_number;j++){
                if(int_number % i ==0){
                    int_number /= i;
                    n++;
                }
            }
            arr[k] = n + 48;
            k++;
            if (int_number != 1){
                arr[k] = ' ';
                k++;
                arr[k] = 'x';
                k++;
                arr[k] = ' ';
                k++;
            }
        }
    }
    return arr;
}

int main(int argc, char** argv)
{
    if(argc < 1)
        return -1;
    
    unsigned int number;
    sscanf(argv[1], "%u", &number);
    
    cout << primeFactorization(number) << endl;
    return 0;
}
