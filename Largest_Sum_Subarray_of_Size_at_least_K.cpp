//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long int ll;

ll maxSumWithK(ll nums[], ll n, ll k) {
    vector<ll> prefixSum(n);
    vector<ll> suffixMax(n);
    ll ans = INT_MIN;

    prefixSum[0] = nums[0];

    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    suffixMax[n - 1] = prefixSum[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        suffixMax[i] = max(suffixMax[i + 1], prefixSum[i]);
    }

    for (int i = 0; i < n - k; ++i) {
        ans = max(ans, suffixMax[i + k] - prefixSum[i]);
    }

    for (int i = k - 1; i < n; ++i) {
        ans = max(ans, prefixSum[i]);
    }

    return ans;
}