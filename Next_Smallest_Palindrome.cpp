//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
    int* makePalindrome(int num[], int n) {
        int* ans = new int[n];

        for (int i = 0; i <= (n - 1) / 2; ++i) {
            ans[i] = num[i];
            ans[n - i - 1] = num[i];
        }

        return ans;
    }

    bool all9(int num[], int n) {
        for (int i = 0; i < n; ++i) {
            if (num[i] != 9) return false;
        }

        return true;
    }

    bool compare(int a[], int b[], int n) {
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) return true;
            if (a[i] < b[i]) return false;
        }

        return false;
    }

public:
    vector<int> generateNextPalindrome(int num[], int n) {
        // code here
        vector<int> ans;

        if (all9(num, n)) {
            ans.push_back(1);
            for (int i = 1; i < n; ++i) ans.push_back(0);
            ans.push_back(1);
            return ans;
        }

        int* palindromeNum = makePalindrome(num, n);

        if (compare(palindromeNum, num, n)) {
            return ans = vector<int>(palindromeNum, palindromeNum + n);
        }

        int carry = 1;

        for (int i = (n - 1) / 2; i >= 0; --i) {
            int value = palindromeNum[i] + carry;
            palindromeNum[i] = value % 10;
            carry = value / 10;
        }

        palindromeNum = makePalindrome(palindromeNum, n);

        return ans = vector<int>(palindromeNum, palindromeNum + n);
    }

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* num = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends