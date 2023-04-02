//{ Driver Code Starts

#include <bits/stdc++.h>
#include<iostream>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    string toughProblem(int n, int s, int x){
        // Code Here
        vector<string> ans = {"Yes", "No"};

        if (s < x || (s + x) % 2 == 1) return ans[1];

        if (n == 1) return s == x ? ans[0] : ans[1];

        if (n == 2) {
            int value = (s - x) / 2;
            for (int bit = 30; bit >= 0; --bit) {
                if ((value & (1 << bit)) > 0) {
                    if ((x & (1 << bit)) > 0) return ans[1];
                }
            }
        }

        return ans[0];
    }
};


//{ Driver Code Starts.


int main() {
    Solution ob;
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n, s, x;
        scanf("%d %d %d", &n, &s, &x);

        cout << ob.toughProblem(n, s, x) << endl;

    }
    return 0;
}
// } Driver Code Ends