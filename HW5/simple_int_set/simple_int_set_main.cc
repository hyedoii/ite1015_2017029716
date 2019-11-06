#include <iostream>
#include <stdlib.h>
#include <set>
#include "simple_int_set.h"

using namespace std;

enum EOperateType
{
    Invalid = -1,
    
    Add,
    Sub,
    Mul,
    Print,
};
typedef enum EOperateType OperateType;

int main(void)
{
    while(true)
    {
        string inputs;
        getline(cin, inputs);
        
        if(inputs == "0") break;
        
        string *argv = new string[inputs.length()]; // more than count
        string token;
        size_t pos;
        int argc = 0;
        
        while(true)
        {
            pos = inputs.find(' ');
            token = inputs.substr(0, pos);
            
            argv[argc++] = token;
            
            if(pos >= inputs.length()) break;
            else inputs.erase(0, pos + 1);
        }
        
        SimpleIntSet *left = NULL;
        SimpleIntSet *right = NULL;
        
        int *elements = NULL;
        int elementCount = 0;
        OperateType type = Invalid;
        set<int> tmp;
        for(int i=0; i<argc; ++i)
        {
            string arg = argv[i];
            if(arg == "{" && elements == NULL) elements = new int[argc];
            else if(isdigit(arg[arg.length() - 1])) {
                elements[elementCount++] = atoi(arg.c_str());
                tmp.insert(atoi(arg.c_str()));
            }
            else if(arg == "}")
            {
                SimpleIntSet *newSet = new SimpleIntSet(elements, elementCount);
                newSet->intSet = tmp;
                if(left == NULL) {
                    left = newSet;
                    tmp = set<int> ();
                }
                else if(right == NULL) right = newSet;
                
                delete elements;
                elements = NULL;
                elementCount = 0;
                
                if(type == Invalid) type = Print;
            }
            else if(arg == "+") type = Add;
            else if(arg == "-") type = Sub;
            else if(arg == "*") type = Mul;
        }
        
        switch(type)
        {
            case Add:
                left->SetUnion(left->intSet, right->intSet);
                break;
                
            case Sub:
                left->SetDifference(left->intSet, right->intSet);
                break;
                
            case Mul:
                left->SetIntersection(left->intSet, right->intSet);
                break;
                
            default: break;
        }
        
        delete left;
        delete right;
    }
    return 0;
}

