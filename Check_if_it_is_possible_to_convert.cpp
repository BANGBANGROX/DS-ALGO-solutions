//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isItPossible(string s, string t, int m, int n) {
        // code here
        if (m != n) return 0;

        vector<pair<char, int>> positionsOfS;
        vector<pair<char, int>> positionsOfT;

        for (int i = 0; i < m; ++i) {
            if (s[i] != '#') {
                positionsOfS.push_back({ s[i],i });
            }
            if (t[i] != '#') {
                positionsOfT.push_back({ t[i], i });
            }
        }

        if (positionsOfS.size() != positionsOfT.size()) return 0;

        for (int i = 0; i < (int)positionsOfS.size(); ++i) {
            if (positionsOfS[i].first != positionsOfT[i].first) return 0;
            if (positionsOfS[i].first == 'A') {
                if (positionsOfS[i].second < positionsOfT[i].second) return 0;
            }
            if (positionsOfS[i].first == 'B') {
                if (positionsOfS[i].second > positionsOfT[i].second) return 0;
            }
        }

        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends