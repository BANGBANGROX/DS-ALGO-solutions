// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    int findSwapValues(int nums1[], int m, int nums2[], int n) {
        // Your code goes here
        ll firstSum = accumulate(nums1, nums1 + m, (ll)0);
        ll secondSum = accumulate(nums2, nums2 + n, (ll)0);
        ll difference = firstSum - secondSum;

        sort(nums2, nums2 + n);
   
        if (abs(difference) % 2 == 1) return -1;

        for (int i = 0; i < m; ++i) {
            int required = nums1[i] - difference / 2;
            if (binary_search(nums2, nums2 + n, required)) return 1;
        }

        return -1;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int* a = new int[n];
        int* b = new int[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];


        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";

    }
    return 0;
}





// } Driver Code Ends