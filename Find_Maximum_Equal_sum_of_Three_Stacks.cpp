// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int maxEqualSum(int n1, int n2, int n3, vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int sum3 = accumulate(nums3.begin(), nums3.end(), 0);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n1 && j < n2 && k < n3) {
            if (sum1 == sum2 && sum1 == sum3) return sum1;
            int maxSum = max({ sum1, sum2, sum3 });
            if (sum1 == maxSum) {
                sum1 -= nums1[i];
                ++i;
            }
            if (sum2 == maxSum) {
                sum2 -= nums2[j];
                ++j;
            }
            if (sum3 == maxSum) {
                sum3 -= nums3[k];
                ++k;
            }
        }

        return 0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for (int i = 0; i < n1; i++) {
            cin >> s1[i];
        }
        for (int i = 0; i < n2; i++) {
            cin >> s2[i];
        }
        for (int i = 0; i < n3; i++) {
            cin >> s3[i];
        }
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}  // } Driver Code Ends