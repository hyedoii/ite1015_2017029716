#include <stdlib.h>
#include <iostream>

using namespace std;

int n;
int* arr;

void sort(){
    int tmp;
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n;j++){
            if(arr[i]>arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(){
    
    cin >> n;
    
    arr = (int*)malloc(sizeof(int)*n);
    
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    
    sort();
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    free(arr);
    
    return 0;
    
}
