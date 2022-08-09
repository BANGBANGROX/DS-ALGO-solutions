//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

typedef long long ll;

ll maxArea(ll nums[], int n) {
    // Your code goes here
    int l = 0;
    int r = n - 1;
    ll ans = 0;
    ll maxL = nums[l];
    ll maxR = nums[r];

    while (l < r) {
        maxL = max(maxL, nums[l]);
        maxR = max(maxR, nums[r]);
        if (maxL < maxR) {
            ans = max(ans, (r - l) * maxL);
            ++l;
        }
        else {
            ans = max(ans, (r - l) * maxR);
            --r;
        }
    }

    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long* arr = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends