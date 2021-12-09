// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:

    string addStrings(string& n1, string& n2) {
        int i = n1.size() - 1, j = n2.size() - 1, carry = 0;
        string ans("");

        while (i >= 0 && j >= 0) {
            int res = (n1[i] - '0') + (n2[j] - '0') + carry;
            carry = res / 10;
            res %= 10;
            ans = to_string(res) + ans;
            --i;
            --j;
        }

        while (i >= 0) {
            int res = (n1[i] - '0') + carry;
            carry = res / 10;
            res %= 10;
            ans = to_string(res) + ans;
            --i;
        }

        while (j >= 0) {
            int res = (n2[j] - '0') + carry;
            carry = res / 10;
            res %= 10;
            ans = to_string(res) + ans;
            --j;
        }

        if (carry) ans = to_string(carry) + ans;

        i = 0;

        while (ans[i] == '0') ans.erase(i, 1);

        return ans;
    }

    string solve(int arr[], int n) {
        // code here
        sort(arr, arr + n);
        
        string num1(""), num2(""), ans("");
        int carry = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i & 1) num1 += to_string(arr[i]);
            else num2 += to_string(arr[i]);
        }

        return addStrings(num1, num2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
