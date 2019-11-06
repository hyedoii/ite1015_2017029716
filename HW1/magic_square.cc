#include <iostream>
#include <string.h>

using namespace std;


int i;
int j;

int magicSquare(int **arr, int num) {
    int putNum = 1;
    int col = ( num - 1 )/ 2;
    int row = 0;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            arr[i][j] = 0;
        }
    }
    for (i = 1; i <= num*num; i++) {
        if (arr[row][col] == 0) {
            arr[row][col] = putNum;
            putNum += 1;
        }
        if (i % num == 0) {
            row += 1;
        }
        else {
            col += 1;
            row -= 1;
        }
        if (row < 0) {
            row = num - 1;
        }
        if (col > num - 1) {
            col = 0;
        }
    }
    return **arr;
}


int main() {
    int num;
    cin >> num;
    if (num <= 0 || num % 2 == 0) return 0;
    int **arr = new int*[num];
    for (i = 0; i < num; ++i) {
        arr[i] = new int[num];
    }
    
    magicSquare(arr, num);
    
    for (i = 0; i < num; ++i) {
        for (j = 0; j < num; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < num; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
