//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    unordered_map<string, int> dp;

    int maxLevelUtil(int h, int m, int previouRoad) {
        if (h <= 0 || m <= 0) return -1;

        if (previouRoad == -1) {
            int ans = max({ maxLevelUtil(h + 3,m + 2,0),maxLevelUtil(h - 5,m - 10,1),
                maxLevelUtil(h - 20,m + 5,2) }) + 1;
            return ans;
        }

        string s = to_string(h) + '$' + to_string(m) + '$' + to_string(previouRoad);

        if (dp.find(s) != dp.end()) return dp[s];

        if (previouRoad == 0) {
            return dp[s] = max(maxLevelUtil(h - 5, m - 10, 1),
                maxLevelUtil(h - 20, m + 5, 2)) + 1;
        }

        if (previouRoad == 1) {
            return dp[s] = max(maxLevelUtil(h + 3, m + 2, 0),
                maxLevelUtil(h - 20, m + 5, 2)) + 1;
        }

        return dp[s] = max(maxLevelUtil(h + 3, m + 2, 0), maxLevelUtil(h - 5, m - 10, 1)) + 1;
    }

public:
    int maxLevel(int h, int m) {
        // code here
        return maxLevelUtil(h, m, -1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    Solution a;
    while (t--)
    {
        int h, m;
        cin >> h >> m;
        cout << a.maxLevel(h, m) << endl;
    }
    return 0;
}
// } Driver Code Ends