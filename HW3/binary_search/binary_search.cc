#include <iostream>
#include "binary_search.h"

using namespace std;
void BinarySearch::sortArray() {
    
        int tmp;
        
        for(int i = 0; i < mArrayCount-1; i++){
            for(int j = i+1; j < mArrayCount;j++){
                if(mArray[i]>mArray[j]){
                    tmp = mArray[i];
                    mArray[i] = mArray[j];
                    mArray[j] = tmp;
                }
            }
        }
    
}
BinarySearch::BinarySearch() {
    
}
BinarySearch::BinarySearch(int *_array, int _arrayCount) {
    int i;
    mArrayCount = _arrayCount;
    mArray = new int[mArrayCount];
    for(i = 0; i < mArrayCount; i++) {
        mArray[i] = _array[i];
    }
    sortArray();
}
BinarySearch::~BinarySearch() {
    delete[] mArray;
}
int BinarySearch::getIndex(int _element) {
    int start = 0;
    int end = mArrayCount - 1;
    int mid;
    
    while(start <= end) {
        mid = (start + end) / 2;
        if(mArray[mid]> _element) end = mid - 1;
        else if(mArray[mid] < _element) start = mid + 1;
        else return mid;//찾은경우
    }
    return - 1;//못찾은경우
}
