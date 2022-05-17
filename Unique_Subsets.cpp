// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    //Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int>& nums, int n) {
        // code here 
        vector<vector<int>> ans;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> currentSet;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) != 0) {
                    currentSet.push_back(nums[i]);
                }
            }
            st.insert(currentSet);
        }

        ans = vector<vector<int>>(st.begin(), st.end());

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
        vector<int> A;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A, n);
        // printing the output
        for (int i = 0; i < result.size(); i++) {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}


// } Driver Code Ends