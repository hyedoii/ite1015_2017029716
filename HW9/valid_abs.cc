#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num, lNum = 0, rNum = 0;
    string input;
    vector<string> inputs;
    
    cin >> num;
    
    for (int i = 0 ; i < num ; ++i) {
        cin >> input;
        inputs.push_back(input);
    }
    
    for (int i = 0 ; i < num ; ++i) {
        lNum =0;
        rNum=0;
        for(int j = 0 ; j < inputs[i].length() ; ++j) {
            if(inputs[i][j] == '<') {
                ++lNum;
            }
            else if(inputs[i][j] == '>') {
                ++rNum;
            }
        }
        if(lNum == rNum) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}


