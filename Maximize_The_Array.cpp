// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int nums1[], int nums2[], int n) {
        // code here 
        vector<pair<int, int>> ans;
        vector<int> res;
        set<int> visited;
        vector<pair<int, int>> nums1Indexed;
        vector<pair<int, int>> nums2Indexed;

        for (int i = 0; i < n; ++i) {
            nums1Indexed.push_back({ nums1[i], i + n });
            nums2Indexed.push_back({ nums2[i],i });
        }

        stable_sort(nums1Indexed.begin(), nums1Indexed.end(),
            [](pair<int, int> a, pair<int, int> b) {
                return a.first != b.first ? a.first > b.first : a.second < b.second;
            });
        stable_sort(nums2Indexed.begin(), nums2Indexed.end(),
            [](pair<int, int> a, pair<int, int> b) {
                return a.first != b.first ? a.first > b.first : a.second < b.second;
            });

        int i = 0;
        int j = 0;

        while (i < n && j < n && (int)ans.size() < n) {
            int val1 = nums1Indexed[i].first;
            int val2 = nums2Indexed[j].first;
            if (visited.find(val1) != visited.end()) {
                ++i;
                continue;
            }
            if (visited.find(val2) != visited.end()) {
                ++j;
                continue;
            }
            if (val1 > val2) {
                ans.push_back(nums1Indexed[i]);
                visited.insert(nums1Indexed[i].first);
                ++i;
            }
            else {
                ans.push_back(nums2Indexed[j]);
                visited.insert(nums2Indexed[j].first);
                ++j;
            }
        }

        if ((int)ans.size() < n) {
            while (i < n && (int)ans.size() < n) {
                if (visited.find(nums1Indexed[i].first) != visited.end()) {
                    ++i;
                    continue;
                }
                ans.push_back(nums1Indexed[i]);
                visited.insert(nums1Indexed[i].first);
                ++i;
            }
            while (j < n && (int)ans.size() < n) {
                if (visited.find(nums2Indexed[j].first) != visited.end()) {
                    ++j;
                    continue;
                }
                ans.push_back(nums2Indexed[j]);
                visited.insert(nums2Indexed[j].first);
                ++j;
            }
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second; });

        for (int i = 0; i < ans.size(); ++i) {
            res.push_back(ans[i].first);
        }

        return res;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int* arr1 = new int[n], * arr2 = new int[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends