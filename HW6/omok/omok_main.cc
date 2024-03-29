#include "omok.h"
#include <iostream>

using namespace std;

int main(){
    Omok stage;
    bool black_win;
    int x, y;
    
    while(!stage.IsOmok(&black_win)){
        cin >> x >> y;
        if(!stage.Put(x,y)) cout << "Can not be placed there." << endl;
    }
    
    cout << stage << "Winner: ";
    if(black_win) cout << "Black player";
    else cout << "White player";
    
    cout << endl;
    
    return 0;
}
