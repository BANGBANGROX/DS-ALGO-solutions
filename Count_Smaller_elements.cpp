//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
    typedef tree<int, null_type, less_equal<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

public:
    vector<int> constructLowerArray(int* arr, int n) {
        // code here
        ordered_set s;
        vector<int> ans(n);

        s.insert(arr[n - 1]);

        for (int i = n - 2; i >= 0; --i) {
            ans[i] = s.order_of_key(arr[i]);
            s.insert(arr[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends