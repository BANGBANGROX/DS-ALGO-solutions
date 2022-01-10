#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            ++freq[nums[i]];
        }

        for (int i = 0; i < n; ++i) {
            if (freq[nums[i]] != 0) {
                if (pq.size() < k) {
                    pq.push({ freq[nums[i]],nums[i] });
                }
                else {
                    pair<int, int> x = pq.top();
                    pq.pop();
                    if (x.first < freq[nums[i]]) {
                        pq.push({ freq[nums[i]],nums[i] });
                    }
                    else {
                        pq.push(x);
                    }
                }
                freq[nums[i]] = 0;
            }
        }

        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) cin >> x;
        cin >> k;

        Solution obj;
        vector<int> ans = obj.topKFrequent(nums, k);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}