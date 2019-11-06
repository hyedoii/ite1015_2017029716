#include "sorted_array.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

SortedArray::SortedArray() {}
SortedArray::~SortedArray() {}

void SortedArray::AddNumber(int num){
    numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending() const {
    
    vector<int> copy = numbers_;
    
    for(int i = 0; i < copy.size(); i++){
        for(int j = i+1; j < copy.size(); j++){
            if(copy[i] > copy[j]){
                int temp;
                temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }
    for(int i = 0; i < copy.size(); i++){
        cout << copy[i] << " ";
    }
    cout << endl;
    
    return copy;
}

vector<int> SortedArray::GetSortedDescending() const {
    vector<int> copy = numbers_;
    for(int i = 0; i < copy.size(); i++){
        for(int j = i+1; j < copy.size(); j++){
            if(copy[i] < copy[j]){
                int temp;
                temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < copy.size(); i++){
        cout << copy[i] << " ";
    }
    cout << endl;
    
    return copy;
}

int SortedArray::GetMax() const {
    int max = 0;
    for(int i = 0; i < numbers_.size(); i++){
        if( max < numbers_[i]){
            max = numbers_[i];
        }
    }
    cout << max << endl;
    
    return max;
}

int SortedArray::GetMin() const {
    int min = 99999999;
    for(int i = 0; i < numbers_.size(); i++){
        if( min > numbers_[i]){
            min = numbers_[i];
        }
    }
    
    cout << min << endl;
    return min;
}

