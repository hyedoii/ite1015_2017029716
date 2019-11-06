// simple_int_set.h
// Implement your simple_int_set.cc

#ifndef __hw03__simple_int_set__
#define __hw03__simple_int_set__

#define MAX_SIZE 1024
#include <set>

using namespace std;

class SimpleIntSet
{
private:
    int *mElements;
    int mElementCount;
    
    SimpleIntSet();
    
public:
    SimpleIntSet(int *_elements, int _count);
    ~SimpleIntSet();
    
    set<int> intSet;
    int *elements() const; // return sorted array
    
    set<int>::iterator it;
    set<int> SetIntersection(const set<int>& set0, const set<int>& set1);
    set<int> SetUnion(const set<int>& set0, const set<int>& set1);
    set<int> SetDifference(const set<int>& set0, const set<int>& set1);
    
    void printSet(set<int>& set0);
};

#endif

