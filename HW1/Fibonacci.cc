#include <iostream>
using namespace std;

int fibonacci(int position){
    if(position == 0){
        return 0;
    }
    else if(position == 1){
        return 1;
    }
    else return fibonacci(position-1)+fibonacci(position-2);
}

void printFunc(int number) {
    if(number > 0){
        printFunc(number - 1);
        cout<<fibonacci(number)<<" ";
    }
}

int main(){
    int n;
    cin >> n;
    if(n > 0)
        printFunc(n);
    cout<<"\n";
    
    return 0;
}
