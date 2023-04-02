//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string secondSmallest(int digitSum, int digitNum) {
        // code here
        vector<int> digits(digitNum);

        for (int i = digitNum - 1; i > 0; --i) {
            int dig = min(digitSum - 1, 9);
            digits[i] = dig;
            digitSum -= dig;
        }

        if (digitSum > 9) return "-1";

        digits[0] = digitSum;

        for (int i = digitNum - 1; i > 0; --i) {
            if (digits[i] != 0 && digits[i - 1] != 9) {
                --digits[i];
                ++digits[i - 1];
                string ans;
                for (int j = 0; j < digitNum; ++j) {
                    ans += char(digits[j] + '0');
                }
                return ans;
            }
        }

        return "-1";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S, D) << endl;
    }
    return 0;
}
// } Driver Code Ends