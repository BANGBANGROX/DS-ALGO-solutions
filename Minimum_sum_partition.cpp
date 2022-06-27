// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minDifference(int arr[], int n) {
        // Your code goes here
        int totalSum = accumulate(arr, arr + n, 0);
        int ans = INT_MAX;
        vector<bool> dp(totalSum + 1);

        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            for (int sum = totalSum; sum >= 0; --sum) {
                if (sum >= arr[i]) dp[sum] = dp[sum] | dp[sum - arr[i]];
            }
        }

        for (int i = 0; i <= totalSum; ++i) {
            if (dp[i] && dp[totalSum - i]) ans = min(ans, abs(2 * i - totalSum));
        }

        return ans;
    }
};


// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends