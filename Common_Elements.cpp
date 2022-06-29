// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    vector<int> common_element(vector<int>& nums1, vector<int>& nums2) {
        // Your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();

        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
            }
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] == nums2[j]) {
                ++i;
                ++j;
            }
            else ++j;
        }

        return ans; 
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int>v1(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        int m;
        cin >> m;
        vector<int>v2(m, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }
        Solution ob;
        vector<int>result;
        result = ob.common_element(v1, v2);
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;

    }
}  // } Driver Code Ends