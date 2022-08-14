//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> kthLargest(int k, int nums[], int n) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans(n);

        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
            ans[i] = (pq.size() == k) ? pq.top() : -1;
        }

        for (int i = k; i < n; ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
            ans[i] = pq.top();
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends