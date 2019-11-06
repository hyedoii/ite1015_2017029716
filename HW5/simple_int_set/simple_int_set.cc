
# include <iostream>
# include <stdlib.h>
# include <set>
# include "simple_int_set.h"

using namespace std;
SimpleIntSet::SimpleIntSet(){}

SimpleIntSet::SimpleIntSet(int *_elements, int _count){
    *mElements = *_elements;
    mElementCount = _count;
    set<int>intSet(*_elements, *_elements + _count);
}

SimpleIntSet::~SimpleIntSet(){
    delete[] elements();
}

set<int> SimpleIntSet::SetIntersection(const set<int>& set0, const set<int>& set1){
    set<int> intersectionSet;
    for(std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it){
        for(std::set<int>::iterator it_ = set1.begin(); it_ != set1.end(); ++it_){
            if(*it == *it_){
                intersectionSet.insert(*it);
            }
        }
    }
    printSet(intersectionSet);
    return intersectionSet;
}

set<int> SimpleIntSet::SetUnion(const set<int>& set0, const set<int>& set1){
    set<int> unionSet = set0;
    for(std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it){
        for(std::set<int>::iterator it_ = set1.begin(); it_ != set1.end(); ++it_){
            if(*it != *it_){
                unionSet.insert(*it_);
            }
        }
    }
    printSet(unionSet);
    return unionSet;
}

set<int> SimpleIntSet::SetDifference(const set<int>& set0, const set<int>& set1){
    set<int> differenceSet = set0;
    for(std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it){
        for(std::set<int>::iterator it_ = set1.begin(); it_ != set1.end(); ++it_){
            if(*it == *it_){
                differenceSet.erase(*it);
            }
        }
    }
    printSet(differenceSet);
    return differenceSet;
}

void SimpleIntSet::printSet(set<int>& set0) {
    cout << "{ ";
    for(std::set<int>::iterator it = set0.begin(); it != set0.end(); ++it){
        cout << *it << ' ';
    }
    cout << "}" <<  endl;
}
