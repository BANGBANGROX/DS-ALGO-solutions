// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/coin-piles5152/1

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minSteps(int a[], int n, int k) {
        // code here
        vector<int> prefix(n);
        int ans = INT_MAX;
        int previousNums = 0;

        sort(a, a + n);

        prefix[0] = a[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }

        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (i + 1 < n && a[i] == a[i + 1]) {
                ++i;
                ++count;
            }
            int required = a[i] + k;
            int idx = upper_bound(a, a + n, required) - a;
            int actualSum = prefix[n - 1] - prefix[idx - 1];
            int requiredSum = required * (n - idx);
            ans = min(ans, actualSum - requiredSum + previousNums);
            previousNums += a[i] * count;
        }

        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        int* A = new int[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.minSteps(A, N, K) << endl;
    }
    return 0;
}  // } Driver Code Ends