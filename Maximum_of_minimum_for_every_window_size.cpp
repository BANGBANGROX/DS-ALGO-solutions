// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to find maximum of minimums of every window size.

    void nextSmaller(int arr[], int n, vector<int>& right) {
        stack<int> s;

        for (int i = n - 1; i > -1; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }
    }

    void prevSmaller(int arr[], int n, vector<int>& left) {
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
    }

    vector <int> maxOfMin(int arr[], int n) {
        // Your code here
        vector<int> left(n, -1), right(n, n), ans(n, 0);

        nextSmaller(arr, n, right);
        prevSmaller(arr, n, left);

        for (int i = 0; i < n; ++i) {
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }

        for (int i = n - 2; i > -1; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
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
        int* a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
