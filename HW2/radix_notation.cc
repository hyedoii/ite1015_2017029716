#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//radix == 진법
//number == 바꿀 숫자

void reverseString(char* s) {
    size_t size = strlen(s);
    char temp;
    
    for (size_t i = 0; i < size / 2; i++) {
        temp = s[i];
        s[i] = s[(size - 1) - i];
        s[(size - 1) - i] = temp;
    }
}

string RadixNotation(unsigned int number, unsigned int radix){
    char arr[100] = {""};
    int i = 0;
    
    while(number >= radix){
        if(number % radix > 9){
            arr[i] = number % radix + 87;
        }
        else{
            arr[i] = number % radix + 48;
        }
        number /= radix;
        i++;
    }
    if(number % radix > 9){
        arr[i] = number + 87;
    }
    else{
        arr[i] = number + 48;
    }
    
    reverseString(arr);
    
    return arr;
}

int main(int argc, char** argv) {
    if (argc < 2) return -1;
    unsigned int radix;
    sscanf(argv[1], "%u", &radix);
    if (radix < 2 || radix > 36) return -1;
    for (int i = 2; i < argc; ++i) {
        unsigned int number;
        sscanf(argv[i], "%u", &number);
        cout << RadixNotation(number, radix) << endl;
    }
    return 0;
}
