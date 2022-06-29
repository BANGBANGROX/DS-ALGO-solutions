// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int kthLargest(vector<int>& nums, int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int len = 1; len <= n; ++len) {
            int sum = 0;
            for (int i = 0; i < len; ++i) {
                sum += nums[i];
            }
            int l = 0;
            int r = len - 1;
            while (r < n) {
                if (pq.size() < k) pq.push(sum);
                else {
                    int top = pq.top();
                    if (sum > top) {
                        pq.pop();
                        pq.push(sum);
                    }
                }
                sum -= nums[l];
                ++l;
                ++r;
                if (r < n) sum += nums[r];
            }
        }

        return pq.top();
    }
};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends