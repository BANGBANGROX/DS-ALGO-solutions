// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> res;

    void towerOfHanoi(int n, int start, int end, int aux, int* state) {
        if (n == 1) {
            *state = *state - 1;
            if (*state == 0) {
                res.push_back(start);
                res.push_back(end);
            }
            return;
        }

        towerOfHanoi(n - 1, start, aux, end, state);

        *state = *state - 1;
        if (*state == 0) {
            res.push_back(start);
            res.push_back(end);
        }

        towerOfHanoi(n - 1, aux, end, start, state);
    }

    vector<int> shiftPile(int N, int n) {
        towerOfHanoi(N, 1, 3, 2, &n);

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, n;
        cin >> N >> n;

        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}  // } Driver Code Ends
