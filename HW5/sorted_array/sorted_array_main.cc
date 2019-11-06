#include "sorted_array.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    SortedArray *arr = new SortedArray;
    
    int n = 0;
    string input;
    getline(cin, input);
    
    for(int i = 0; i < input.length() ; i++){
        if(input[i] != ' '){
            n = n*10;
            n = n + input[i]-48;
        }
        else if( input[i] == ' ' || input[i] == '\n'){
            arr->AddNumber(n);
            n = 0;
        }
    }
    
    arr->AddNumber(n);
    
    while(true){
        n = 0;
        
        cin >> input;
        
        if ( input == "ascend" ){
            arr->GetSortedAscending();
        }
        else if ( input == "descend" ){
            arr->GetSortedDescending();
        }
        else if ( input == "max" ) {
            arr->GetMax();
        }
        else if ( input == "min" ) {
            arr->GetMin();
        }
        else if ( input == "quit" ){
            break;
        }
        else {
            for(int i = 0; i < input.length() ; i++){
                if(input[i] != ' '){
                    n = n*10;
                    n = n + input[i]-48;
                }
                else if( input[i] == ' ' || input[i] == '\n'){
                    arr->AddNumber(n);
                    n = 0;
                }
            }
            
            arr->AddNumber(n);
        }
    }
    return 0;
}
