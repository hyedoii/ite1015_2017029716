#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#define MINUS -999
#define PLUS 999
using namespace std;

class Variable {
public:
    int degree_;
    int constant_;
    int plus_state_;
    
    Variable(int degree,int constant,int plus_state) {
        degree_ = degree;
        constant_ = constant;
        plus_state_ = plus_state;
    }
    
    int GetDiff(int x) {
        
        if(degree_==1) {
            if(plus_state_ == MINUS) {
                return constant_ * -1;
            } else{
                return constant_;
            }
        } else if(degree_==0) {
            return 0;
        } else {
            if(plus_state_ == MINUS) {
                return degree_ * constant_* (-1) * pow((double)x,(double)(degree_-1));
            } else {
                return degree_ * constant_ * pow((double)x,(double)(degree_-1));
            }
        }
        
    }
    int GetPlusState() {
        return degree_;
    }
};

class PolyDiff {
public:
    vector<Variable> variables_;
    
    void SetVariables(string data){
        int constant=0,degree=0,plus_state=PLUS,s=0,t=0;
        
        char *cstr = new char [data.length()+1];
        strcpy(cstr,data.c_str());
        char *token = strtok(cstr, "+\n");
        
        while(token != NULL){
            
            for(int i=0; i<strlen(token);  i++) {
                if(token[0]=='-') {
                    plus_state = MINUS;
                }
                
                if(token[i]=='x' && i>0){
                    
                    //1아닌 상수가있다면,
                    char temp1[5];
                    
                    for(int j=0; j<i; j++){
                        if(token[j]>='0' && token[j]<='9') {
                            temp1[t++] = token[j];
                        }
                    }
                    constant = atoi(temp1);
                    memset(temp1, 0, sizeof(char) * 5);
                }
                
                //제곱승이 있다면(2이상)
                if(token[i]=='^'){
                    char temp2[5];
                    
                    for(int j=i; j<strlen(token); j++){
                        if(token[j]>='0' && token[j]<='9') {
                            temp2[s++] = token[j];
                        }
                    }
                    degree = atoi(temp2);
                    memset(temp2, 0, sizeof(char) * 5);
                }
                
                if(i==(strlen(token)-1) && token[i]=='x')
                    degree=1;
            }
            
            if(degree >= 1 && constant==0)
                constant=1;
            
            Variable vb(degree,constant,plus_state);
            variables_.push_back(vb);
            token = strtok(NULL, "+\n");
            degree=0,constant=0,s=0,t=0;
            plus_state=PLUS;
        }
    }
    
    void GetDiff(int x) {
        double result;
        
        vector<Variable>::iterator it;
        for(it=variables_.begin(); it!=variables_.end(); it++) {
            result += it->GetDiff(x) ;
        }
        cout << (int)result << endl;
        variables_.clear();
    }
};

int main(void) {
    string data;
    PolyDiff poly_;
    int x;
    
    while(true) {
        cin >> data;
        if (data == "quit") {
            break;
        } else {
            poly_.SetVariables(data);
            cin >> x;
            poly_.GetDiff(x);
        }
    }
    return 0;
}

