// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    typedef long long int ll;

    string add(string num1, string num2) {
        string ans("");
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0) {
            int val = num1[i] - '0' + num2[j] - '0' + carry;
            ans = to_string(val % 10) + ans;
            carry = val / 10;
            --i;
            --j;
        }

        while (i >= 0) {
            int val = num1[i] - '0' + carry;
            ans = to_string(val % 10) + ans;
            carry = val / 10;
            --i;
        }

        while (j >= 0) {
            int val = num2[i] - '0' + carry;
            ans = to_string(val % 10) + ans;
            carry = val / 10;
            --j;
        }

        if (carry > 0) ans = to_string(carry) + ans;

        if (ans.empty()) ans += '0';

        return ans;
    }

public:
    ll minSum(int arr[], int n) {
        // Your code goes here
        string num1("");
        string num2("");

        sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) num1 += to_string(arr[i]);
            else num2 += to_string(arr[i]);
        }

        return stoll(add(num1, num2));
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
        int* arr = new int[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minSum(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends