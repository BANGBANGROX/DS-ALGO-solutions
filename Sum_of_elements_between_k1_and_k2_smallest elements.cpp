// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    ll sumBetweenTwoKth(ll nums[], ll n, ll k1, ll k2) {
        // Your code goes here
        sort(nums, nums + n);

        return accumulate(nums + k1, nums + k2 - 1, 0);
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        long long* a = new long long[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;

    }
    return 0;
}
// } Driver Code Ends