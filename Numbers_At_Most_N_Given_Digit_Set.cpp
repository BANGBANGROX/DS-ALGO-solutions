#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int K = s.size();
        vector<int> dp(K + 1);

        dp[K] = 1;

        for (int i = K - 1; i >= 0; --i) {
            int dig = s[i] - '0';
            for (string d : digits) {
                if (dig > stoi(d)) {
                    dp[i] += pow(digits.size(), K - i + 1);
                }
                else if (dig == stoi(d)) {
                    dp[i] += dp[i + 1];
                }
            }
        }

        for (int i = 1; i < K; ++i) {
            dp[0] += pow(digits.size(), i);
        }

        return dp[0];
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int size, n;
        cin >> size;
        vector<string> digits(size);
        for (string& x : digits) cin >> x;
        cin >> n;

        Solution obj;
        cout << obj.atMostNGivenDigitSet(digits, n) << endl;
    }

    return 0;
}