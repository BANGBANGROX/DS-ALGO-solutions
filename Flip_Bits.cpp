//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    int getNumberOfOnes(int a[], int n) {
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                ++result;
            }
        }

        return result;
    }

public:
    int maxOnes(int nums[], int n) {
        // Your code goes here
        int cnt = 0;
        int maxCnt = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++cnt;
            }
            else {
                --cnt;
            }
            maxCnt = max(maxCnt, cnt);
            if (cnt < 0) {
                cnt = 0;
            }
        }

        return maxCnt + getNumberOfOnes(nums, n);
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int* a = new int[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxOnes(a, n) << endl;
    }

    return 0;
}

// } Driver Code Ends