#include "point2d.h"
#include <iostream>
#include <map>
#include <ctype.h>
#include <string>

using namespace std;

int main(){
    map <string, Point> pnt;
    string cmd;
    int printType = 0;
    Point result = *new Point();
    
    while(true){
        printType = 0;
        
        cin >> cmd;
        
        if(cmd.find("set") != -1){
            string name;
            int x, y;
            cin >> name >> x >> y;
            Point something = *new Point(x, y);
            pnt.insert(make_pair(name,something));
        }
        
        else if(cmd.find("eval") != -1){
            string left, oper, right;
            cin >> left >> oper >> right;
            
            if(pnt.count(left) == 0){
                if(isdigit(left[0]) != 0){
                    Point something = *new Point(stoi(left),stoi(left));
                    pnt.insert(make_pair(left,something));
                }
                else{
                    printType = 1;
                }
            }
            if(pnt.count(right) == 0){
                if(isdigit(right[0]) != 0){
                    Point something = *new Point(stoi(right), stoi(right));
                    pnt.insert(make_pair(right,something));
                }
                else{
                    printType = 1;
                }
            }
            
            if(oper == "+"){
                result = operator+(pnt[left], pnt[right]);
            }
            else if(oper == "-"){
                result = operator-(pnt[left], pnt[right]);
            }
            else if(oper == "*"){
                result = operator*(pnt[left], pnt[right]);
            }
            else{
                break;
            }
            
            switch(printType){
                case 0 :
                    cout << "(" << result.x_ << "," << result.y_ << ")" << endl;
                    break;
                case 1 :
                    cout << "input error" << endl;
                    break;
            }
        }
        else{
            break;
        }
    }
    return 0;
}



