#include <iostream>
#include <vector>

using namespace std;

bool triTest(vector<int> triangleNum, int test) {
    int testNum;
    for (int i = 0; i< triangleNum.size(); ++i) {
        for( int j = i ; j< triangleNum.size() ; ++j) {
            for( int k = j; k< triangleNum.size() ; ++k) {
                testNum = triangleNum[i]+triangleNum[j]+triangleNum[k];
                if(testNum == test) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main () {
    int num;
    int input;
    vector<int> inputs;
    vector<int> triangleNum;
    
    for(int i = 1; i < 46; ++i) {
        triangleNum.push_back(i*(i+1)/2);
    }
    
    cin >> num;
    
    for(int i = 0; i < num ; ++i) {
        cin >> input;
        inputs.push_back(input);
    }
    
    for(int a = 0; a < num ; ++a) {
        int test = inputs[a];
        if(triTest(triangleNum, test)){
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}

