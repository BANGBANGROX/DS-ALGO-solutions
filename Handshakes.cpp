// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> dp;

    int countUtil(int n) {
        if (n % 2 == 1) return 0;

        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        // Let's say we have 6 people, we do it like (1,2) (3,4) and (5,6)
        // In general we take 2 people and then partition around those two
        // [0...i] [i+1 i+2] [...n-2-i]
        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            ans += countUtil(i) * countUtil(n - 2 - i);
        }
        
        return dp[n] = ans;
    }
public:
    int count(int n) {
        // code here
        dp = vector<int>(n + 1, -1);

        return countUtil(n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0;
}  // } Driver Code Ends