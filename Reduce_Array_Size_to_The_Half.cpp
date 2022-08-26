#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int> &nums) {
        unordered_map<int, int> count;
        priority_queue<int> pq;
        int ans = 0;
        int removed = 0;
        int n = nums.size();

        for (int num: nums) {
            ++count[num];
        }

        for (const pair<int, int> &x: count) {
            pq.push(x.second);
        }

        while (removed < n / 2) {
            removed += pq.top();
            ++ans;
            pq.pop();
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &x: nums) {
            cin >> x;
        }

        Solution solution;
        cout << solution.minSetSize(nums) << endl;
    }

    return 0;
}