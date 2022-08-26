#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> need;

        for (int num: nums) {
            ++count[num];
        }

        for (int num: nums) {
            if (count[num] == 0) continue;
            if (need[num] > 0) {
                --need[num];
                --count[num];
                ++need[num + 1];
            }
            else if (count[num] > 0 && count[num + 1] > 0 && count[num + 2] > 0) {
                --count[num];
                --count[num + 1];
                --count[num + 2];
                ++need[num + 3];
            }
            else return false;
        }

        return true;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &x: nums) cin >> x;

        Solution solution;
        cout << solution.isPossible(nums) << endl;
    }

    return 0;
}