#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> kLargest(int a[], int n, int k) {
        // code here
        priority_queue<int> pq;
        vector<int> res;
        
        for (int i = 0; i < n; ++i) pq.push(a[i]);

        while (!pq.empty() && k--) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends