// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    bool nextPermutationUtil(vector<int>& a) {
        int n = a.size();

        if (n == 1) return false;

        int last = n - 2;

        while (last >= 0 && a[last] >= a[last + 1]) {
            --last;
        }

        if (last < 0) return false;

        int nextGreater = n - 1;

        for (int i = n - 1; i > last; --i) {
            if (a[i] > a[last]) {
                nextGreater = i;
                break;
            }
        }

        swap(a[last], a[nextGreater]);
        reverse(a.begin() + last + 1, a.end());

        return true;
    }

public:
    vector<int> nextPermutation(int n, vector<int>& arr) {
        // code here
        if (!nextPermutationUtil(arr)) {
            reverse(arr.begin(), arr.end());
        }

        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends