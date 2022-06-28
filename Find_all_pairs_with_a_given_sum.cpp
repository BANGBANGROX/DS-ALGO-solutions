// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int search(int nums[], int key, int n) {
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums[mid] == key) return mid;
            if (nums[mid] > key) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }

public:
    vector<pair<int, int>> allPairs(int nums1[], int nums2[], int m, int n, int target) {
        // Your code goes here   
        vector<pair<int, int>> ans;

        sort(nums1, nums1 + m);
        sort(nums2, nums2 + n);

        for (int i = 0; i < m; ++i) {
            int required = target - nums1[i];
            int index = search(nums2, required, n);
            if (index != -1) {
                ans.push_back({ nums1[i],nums2[index] });
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};


// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;

    while (t--) {
        int N, M, X;
        cin >> N >> M >> X;
        int* A = new int[N], * B = new int[M];

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(A, B, N, M, X);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else {
            for (int i = 0; i < sz; i++) {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends