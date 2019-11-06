#include <iostream>

using namespace std;

int x, y, x_max = 0, y_max = 0;
char arr[200][200];

int main(){
    
    for(int i = 0 ; i < 200 ; i++){
        for (int j = 0 ; j <200 ; j++){
            arr[i][j] = '.';
        }
    }
    
    while(true){
    
        cin >> x;
        cin >> y;
        
        if(x > x_max) x_max = x;
        if(y > y_max) y_max = y;
        
        if(x<0 || y<0) return 0;
    
        arr[y][x] = '*';
        
        for(int i = 0 ; i <= y_max ; i++){
            for(int j = 0 ; j <= x_max ; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
