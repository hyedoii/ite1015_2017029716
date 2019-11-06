#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {
    int input, totalTestNum, countTestNum = 0;
    float percent;
    vector<int> cases;
    
    srand(time(NULL));
    
    cin >> input;
    cin >> totalTestNum;
    
    
    for(int i = 0; i < totalTestNum ; ++i) {
        cases.clear();
        for(int i = 0; i < 3; ++i) {
            cases.push_back(0);
        }
        cases[rand()%3] = 1;
        
        int select = rand()%3;
        
        if(cases[select] == 1){
            switch (input) {
                case 1:
                    ++countTestNum;
                    break;
                case 2:
                    break;
                case 3:
                    input = rand()%2 + 1;
                    switch (input) {
                        case 1:
                            ++countTestNum;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }
        else if(cases[select] == 0){
            switch (input) {
                case 1:
                    break;
                case 2:
                    ++countTestNum;
                    break;
                case 3:
                    input = rand()%2 + 1;
                    switch (input) {
                        case 1:
                            break;
                        case 2:
                            ++countTestNum;
                    }
                    break;
            }
        }
    }
    
    printf("%0.1f%% (%d/%d)\n",(float)countTestNum/(float)totalTestNum * 100, countTestNum, totalTestNum);
    
    return 0;
}


