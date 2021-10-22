// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        // Complete the function
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] <= k) ++cnt;
        }

        int left = 0, right = cnt - 1, bad = 0;

        for (int i = left; i <= right; ++i) {
            if (a[i] > k) ++bad;
        }

        int minSwaps = bad;

        while (left < n && right < n) {
            minSwaps = min(minSwaps, bad);
            if (a[left] > k)--bad;
            ++left;
            ++right;
            if (right < n && a[right] > k) ++bad;
        }

        return minSwaps;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends