//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getSum(int x, int y, int z) {
        // Your code goes here
        const int MOD = 1e9 + 7;
        vector<vector<vector<long>>> exactSum(x + 1, 
            vector<vector<long>>(y + 1, vector<long>(z + 1)));
        vector<vector<vector<long>>> exactNum(x + 1,
            vector<vector<long>>(y + 1, vector<long>(z + 1)));
        long ans = 0;

        exactNum[0][0][0] = 1;

        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                for (int k = 0; k <= z; ++k) {
                    if (i > 0) {
                        exactSum[i][j][k] = (exactSum[i][j][k] + 
                            exactSum[i - 1][j][k] * 10 + 
                            exactNum[i - 1][j][k] * 4) % MOD;
                        exactNum[i][j][k] = (exactNum[i][j][k] + 
                            exactNum[i - 1][j][k]) % MOD;
                    }
                    if (j > 0) {
                        exactSum[i][j][k] = (exactSum[i][j][k] +
                            exactSum[i][j - 1][k] * 10 +
                            exactNum[i][j - 1][k] * 5) % MOD;
                        exactNum[i][j][k] = (exactNum[i][j][k] +
                            exactNum[i][j - 1][k]) % MOD;
                    }
                    if (k > 0) {
                        exactSum[i][j][k] = (exactSum[i][j][k] +
                            exactSum[i][j][k - 1] * 10 +
                            exactNum[i][j][k - 1] * 6) % MOD;
                        exactNum[i][j][k] = (exactNum[i][j][k] +
                            exactNum[i][j][k - 1]) % MOD;
                    }
                    ans = (ans + exactSum[i][j][k]) % MOD;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends