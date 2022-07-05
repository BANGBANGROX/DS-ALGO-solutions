// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<vector<string>> ans;
    vector<string> current;
    string s;
    int n;

    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }

        return true;
    }

    void generate(int index, string currentString) {
        if (index == n) {
            if (!currentString.empty() && isPalindrome(currentString)) {
                current.push_back(currentString);
                ans.push_back(current);
                current.pop_back();
            }
            return;
        }

        currentString.push_back(s[index]);

        if (isPalindrome(currentString)) {
            current.push_back(currentString);
            generate(index + 1, "");
            current.pop_back();
        }

        generate(index + 1, currentString);

        currentString.pop_back();
    }

public:
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        this->s = s;
        n = s.size();
        string currentString("");

        generate(0, currentString);

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends