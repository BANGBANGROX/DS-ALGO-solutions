// { Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string convert(string s, int n) {
        unordered_map<int, string> spiral;
        string res("");
        int ind = 0, pointer = 0, len = s.size();
        bool toggle = false;

        if (n >= len || n == 1) return s;

        while (ind < len) {
            spiral[pointer] += s[ind];
            ++ind;
            if (pointer == 0) toggle = false;
            if (pointer == n - 1) toggle = true;
            if (toggle) --pointer;
            else ++pointer;
        }

        for (int i = 0; i < n; ++i) {
            res += spiral[i];
        }

        return res;
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convert(str, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
