// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> remainders(k);
        int n = nums.size();

        if ((n & 1) > 0) return false;

        for (int num : nums) {
            ++remainders[num % k];
        }

        if ((remainders[0] & 1) > 0) return false;

        for (int i = 1; i < k; ++i) {
            if (remainders[i] != remainders[k - i]) return false;
        }

        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends