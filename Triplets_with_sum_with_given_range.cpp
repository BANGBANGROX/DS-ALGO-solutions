// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int count(int a[], int n, int val) {
        int ans = 0;

        for (int i = 0; i < n - 2; ++i) {
            if (a[i] > val) break;
            int l = i + 1, r = n - 1, sum = val - a[i];
            while (l < r) {
                int currSum = a[l] + a[r];
                if (currSum > sum) --r;
                else {
                    ans += (r - l);
                    ++l;
                }
            }
        }

        return ans;
    }

    int countTriplets(int a[], int n, int l, int r) {
        // code here
        sort(a, a + n);

        return count(a, n, r) - count(a, n, l - 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int* Arr = new int[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends
