#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> original;
    vector<int> current;
    int n;

    Solution(vector<int>& nums) {
        current = original = vector<int>(begin(nums), end(nums));
        n = nums.size();
    }

    vector<int> reset() {
        current = vector<int>(begin(original), end(original));
        return original;
    }

    vector<int> shuffle() {
        next_permutation(current.begin(), current.end());

        return current;
    }

    void print() {
        for (int x : current) cout << x << " ";
        cout << endl;
    }
};

int main() {
    vector<int> nums{ 1,2,3 };

    Solution obj(nums);

    obj.shuffle();
    obj.print();

    obj.reset();
    obj.print();

    obj.shuffle();
    obj.print();

    return 0;
}