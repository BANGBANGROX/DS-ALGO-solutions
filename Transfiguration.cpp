// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    int transfigure(string a, string b) {
        // Your code goes here
        unordered_map<char, int> count;
        int m = a.size();
        int n = b.size();
        int ans = 0;
        int i = m - 1;
        int j = n - 1;

        if (m != n) return -1;

        for (char ch : a) {
            ++count[ch];
        }

        for (char ch : b) {
            --count[ch];
        }

        for (const pair<char, int>& x : count) {
            if (x.second > 0) return -1;
        }

        while (i >= 0 && j >= 0) {
            while (i >= 0 && a[i] != b[j]) {
                ++ans;
                --i;
            }
            if (i >= 0) {
                --i;
                --j;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure(A, B) << endl;
    }
}  // } Driver Code Ends