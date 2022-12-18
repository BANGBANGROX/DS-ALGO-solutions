#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> index;
    vector<int> nums;

public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (index.find(val) != index.end()) return false;

        index[val] = (int)nums.size();
        nums.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (index.find(val) == index.end()) return false;

        int lastValue = nums.back();
        int valIndex = index[val];

        if (valIndex != (int)nums.size() - 1) {
            nums[valIndex] = lastValue;
            index[lastValue] = valIndex;
        }

        nums.pop_back();
        index.erase(val);

        return true;
    }

    int getRandom() {
        int ind = rand() % (int)nums.size();

        return nums[ind];
    }
};

int main() {
    RandomizedSet rs;

    cout << rs.insert(0) << endl;
    cout << rs.insert(1) << endl;
    cout << rs.insert(2) << endl;
    cout << rs.insert(0) << endl;
    cout << rs.remove(1) << endl;
    cout << rs.getRandom() << endl;

	return 0;
}