//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution {
public:
    /*You are required to complete this method*/
    int maxChainLen(val p[], int n) {
        //Your code here
        sort(p, p + n, [](val a, val b) {
            return a.first < b.first;
        });

        int ans = 1;
        int r = p[0].second;

        for (int i = 1; i < n; ++i) {
            if (p[i].first > r) {
                ++ans;
                r = p[i].second;
            }
            else r = min(r, p[i].second);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        Solution ob;
        cout << ob.maxChainLen(p, n) << endl;
    }
    return 0;
}
// } Driver Code Ends