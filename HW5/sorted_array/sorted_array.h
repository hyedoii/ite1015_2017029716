#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_
#include <vector>

using namespace std;

class SortedArray{
	public:
		SortedArray();
		~SortedArray();
		void AddNumber(int num);

		vector<int>GetSortedAscending() const;
		vector<int>GetSortedDescending() const;
		int GetMax() const;
		int GetMin() const;
    
	private:
        vector<int> numbers_;
};

#endif
