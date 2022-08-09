//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution {
public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
        int ans = 0;

        while (pq.size() > 1) {
            int a = pq.top();
            if (a >= k) return ans;
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            ++ans;
        }

        return ans;
    }
};

//{ Driver Code Starts.
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
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends