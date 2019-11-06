# include <iostream>
# include <stdlib.h>
# include <set>
# include "simple_int_set.h"

using namespace std;

SimpleIntSet::SimpleIntSet(int *_elements, int _count){
    *mElements = *_elements;
    mElementCount = _count;
}

SimpleIntSet::~SimpleIntSet(){
    delete[] elements;
}

void SimpleIntSet::sortElements(){
    int tmp;
    
    for(int i = 0; i < _count-1; i++){
        for(int j = i+1; j < _count;j++){
            if(elements[i]>elements[j]){
                tmp = elements[i];
                elements[i] = elements[j];
                elements[j] = tmp;
            }
        }
    }
}
SimpleIntSet::SimpleIntSet(){}

int SimpleIntSet::*elements() const {
    elements[] = sortElements(elements[]);
    return elements[];
} // return sorted array

int SimpleIntSet::elementCount() const {
    int i;
    for(i=0;i<MAX_SIZE; ++i)
    {
        int s = elements[i];
        if(s.empty() == true) break;
    }
    return i;
}

SimpleIntSet::SimpleIntSet *unionSet(SimpleIntSet& _operand){
    
} // 합집합
SimpleIntSet::SimpleIntSet *differenceSet(SimpleIntSet& _operand){
    
}// 차집합
SimpleIntSet::SimpleIntSet *intersectSet(SimpleIntSet& _operand){
    
} // 교집합

void SimpleIntSet::printSet() {
    
}
