#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long int ll;

    const int MOD = (int)1e9 + 7;
    vector<vector<vector<vector<ll>>>> dp;

    ll countSteppingNumbersHandler(int index,
        int toCompare, int isZero, int lastDigit, string& s) {
        if (index == (int)s.size()) return isZero == 1 ? 0 : 1;

        if (dp[index][toCompare][isZero][lastDigit + 1] != -1)
            return dp[index][toCompare][isZero][lastDigit + 1];

        ll result = 0;
        int limit = 9;

        if (toCompare == 1) {
            limit = s[index] - '0';
        }

        for (int digit = 0; digit <= limit; ++digit) {
            int nextToCompare = toCompare;
            int nextIsZero = isZero;
            if (digit < limit) {
                nextToCompare = 0;
            }
            if (digit > 0) {
                nextIsZero = 0;
            }
            if (isZero == 1) {
                result = (result +
                    countSteppingNumbersHandler(index + 1, nextToCompare,
                        nextIsZero, digit, s)) % MOD;
            }
            else {
                if (abs(digit - lastDigit) == 1) {
                    result = (result +
                        countSteppingNumbersHandler(index + 1, nextToCompare,
                            nextIsZero, digit, s)) % MOD;
                }
            }
        }

        return dp[index][toCompare][isZero][lastDigit + 1] = result;
    }

public:
    int countSteppingNumbers(string low, string high) {
        dp = vector<vector<vector<vector<ll>>>>(102, 
            vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(11, -1))));

        ll firstResult = countSteppingNumbersHandler(0, 1, 1, -1, high);

        dp = vector<vector<vector<vector<ll>>>>(102,
            vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(11, -1))));

        ll secondResult = countSteppingNumbersHandler(0, 1, 1, -1, low);
        bool toTakeLow = true;
        
        for (int i = 1; i < (int)low.size(); ++i) {
            if (abs(low[i] - low[i - 1]) != 1) {
                toTakeLow = false;
                break;
            }
        }

        return (firstResult - secondResult + (toTakeLow ? 1 : 0) + MOD) % MOD;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string low, high;
        cin >> low >> high;

        Solution solution;
        cout << solution.countSteppingNumbers(low, high) << endl;
    }
}