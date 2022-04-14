#include<bits/stdc++.h>
using namespace std;

class KthLargest {
	multiset<int> s;
	multiset<int>::iterator kPointer;

public:
    KthLargest(int k, vector<int>& nums) {
		for (int num : nums) {
			s.insert(-1 * num);
		}

		s.insert(INT_MAX);

		kPointer = s.begin();

		for (int i = 1; i < k; ++i) {
			++kPointer;
		}
    }

    int add(int val) {
		val *= -1;

		s.insert(val);

		if (val < *kPointer) --kPointer;
		
		return *kPointer;
    }
};

int main() {
	vector<int> nums = { 4,5,8,2 };
	KthLargest kthLargest(3, nums);

	cout << kthLargest.add(3) << endl;   // return 4
	cout << kthLargest.add(5) << endl;   // return 5
	cout << kthLargest.add(10) << endl;  // return 5
	cout << kthLargest.add(9) << endl;   // return 8
	cout << kthLargest.add(4) << endl;   // return 8

	return 0;
}