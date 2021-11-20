// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:

    ll countSubarraySumX(vector<int>& a, int n, ll x) {
        ll sum = 0, res = 0;
        int start = 0, end = 0;

        while (end < n) {
            sum += (ll)a[end];
            while (start <= end && sum > x) {
                sum -= a[start];
                ++start;
            }
            res += ((ll)end - start + 1);
            ++end;
        }

        return res;
    }

    ll countSubarray(int n, vector<int>& a, ll L, ll R) {
        // code here
        ll Rcnt = countSubarraySumX(a, n, R);
        ll Lcnt = countSubarraySumX(a, n, L - 1);

        return Rcnt - Lcnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        ll L, R;
        cin >> N >> L >> R;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N, A, L, R);
        cout << ans << endl;
    }
}    // } Driver Code Ends