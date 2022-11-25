//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minInsAndDel(int nums1[], int nums2[], int m, int n) {
        // code here
        vector<int> lis;

        for (int i = 0; i < m; ++i) {
            if (binary_search(nums2, nums2 + n, nums1[i])) {
                int idx = lower_bound(lis.begin(), lis.end(), nums1[i]) - 
                    lis.begin();
                if (idx >= (int)lis.size()) lis.push_back(nums1[i]);
                else lis[idx] = nums1[i];
            }
        }

        return m + n - 2 * (int)lis.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        int* A = new int[N], * B = new int[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends