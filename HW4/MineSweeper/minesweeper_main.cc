#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

#include "minesweeper.h"

using namespace std;

int main(){
    Minesweeper *mine = new Minesweeper();
    
    string input;
    int x, y;
    while(true){
        getline(cin, input);
    
        if(input.find("set") != -1){
            int x = input[input.length() - 1];
            int y = input[input.length() - 3];
            mine->map_.resize(y);
            string tmp;
            for(int i = 0; i < y ; i++){
                getline(cin,mine->map_[i]);
                for(int j = 0; j < x ; j++){
                    mine->map1[j][i] = mine->mineCount(j,i);
                    tmp.push_back('_');
                }
                mine->map2[i] = tmp;
            }
        }
        
        else if(input.find("toggle") != -1){
            int x = input[input.length() - 1];
            int y = input[input.length() - 3];
            mine->toggleMine(x, y);
        }
        
        else if(input.find("play") != -1){
            
        }
        
        else if(input.find("touch") != -1){
            int x = input[input.length() - 1];
            int y = input[input.length() - 3];
            int count = mine->touchCount();
            if(mine->touchMap(y,x)== false) cout << "DEAD(" << count << ")" <<endl;
            else{
                
            }
        }
        
        else break;
    }
}
