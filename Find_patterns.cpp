//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int numberOfSubsequences(string text, string pattern) {
        // code here 
        int ans = 0;
        int m = text.length();
        int n = pattern.length();
        vector<bool> visited(m);

        for (int i = 0; i < m; ++i) {
            if (text[i] == pattern[0] && !visited[i]) {
                int idx = 1;
                for (int j = i + 1; j < m && idx < n; ++j) {
                    if (text[j] == pattern[idx] && !visited[j]) {
                        ++idx;
                        visited[j] = true;
                    }
                }
                if (idx == n) ++ans;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S, W) << endl;
    }
    return 0;
}


// } Driver Code Ends