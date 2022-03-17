// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int count(int n, vector<int>& nums, int target) {
        // code here
        int ans = INT_MAX;
        int oneBits = 0;

        for (int bitSize = 31; bitSize >= 0; --bitSize) {
            int changes = 0;
            int state = (target & (1 << bitSize));
            for (int i = 0; i < n; ++i) {
                if ((nums[i] & (1 << bitSize)) == 0) {
                    if (state > 0) nums[i] = INT_MAX;
                    ++changes;
                }
            }
            if (state > 0) oneBits += changes;
            else ans = min(ans, changes + oneBits);
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N >> X;
        vector<int> A(N);
        for (auto& i : A)
            cin >> i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout << ans << endl;
    }
}  // } Driver Code Ends