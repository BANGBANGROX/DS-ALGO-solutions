//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
public:
    int isValid(string s) {
        // code here
        int n = s.size();
        int dotCount = 0;

        for (int i = 0; i < n; ++i) {
            string current("");
            while (i < n && s[i] != '.') {
                if (!isdigit(s[i])) return 0;
                current += s[i];
                ++i;
            }
            if (current.empty() || (current[0] == '0' && (int)current.size() > 1)) return 0;
            if (i == n) break;
            ++dotCount;
            int currentNumber = stoi(current);
            if ((int)current.size() > 3 ||
                currentNumber == 0 && current.size() > 1 || currentNumber > 255)
                return 0;
        }

        return dotCount == 3;
    }
};//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends