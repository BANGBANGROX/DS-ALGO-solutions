#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        multiset<int> ms;
        vector<int> ans(n);

        for (int x : nums1) ms.insert(x);

        for (int i = 0; i < n; ++i) {
            auto it = ms.upper_bound(nums2[i]);
            if (it == ms.end()) {
                ans[i] = *ms.begin();
                ms.erase(ms.begin());
            }
            else {
                ans[i] = *it;
                ms.erase(it);
            }
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
        vector<int> nums1(n), nums2(n);
        for (int& x : nums1) cin >> x;
        for (int& x : nums2) cin >> x;

        Solution obj;
        vector<int> ans = obj.advantageCount(nums1, nums2);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
