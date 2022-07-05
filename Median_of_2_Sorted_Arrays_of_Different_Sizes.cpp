// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2) {
        // Your code goes here
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) return MedianOfArrays(nums2, nums1);

        int l = 0;
        int r = m;

        while (l <= r) {
            int cut1 = (l + ((r - l) >> 1));
            int cut2 = (m + n + 1) / 2 - cut1;
            int left1 = (cut1 > 0) ? nums1[cut1 - 1] : INT_MIN;
            int left2 = (cut2 > 0) ? nums2[cut2 - 1] : INT_MIN;
            int right1 = (cut1 < m) ? nums1[cut1] : INT_MAX;
            int right2 = (cut2 < n) ? nums2[cut2] : INT_MAX;
            if (left1 <= right2 && left2 <= right1) {
                if (((m + n) & 1) == 0) {
                    return ((double) max(left1, left2) + min(right1, right2)) / 2.0;
                }
                return max(left1, left2);
            }
            if (left1 > right2) r = cut1 - 1;
            else l = cut1 + 1;
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
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i) {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}


// } Driver Code Ends