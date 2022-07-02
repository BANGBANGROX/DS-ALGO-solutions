// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    set<string> ans;
    string s;

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    void generate(int index, string current) {
        if (index == (int)s.size()) {
            if (!current.empty() && !isVowel(current.back())) ans.insert(current);
            return;
        }

        if (isVowel(s[index]) || !current.empty()) {
            current.push_back(s[index]);
            generate(index + 1, current);
            current.pop_back();
        }
        
        generate(index + 1, current);
    }

public:
    set<string> allPossibleSubsequences(string s) {
        // code here
        this->s = s;
        string current("");

        generate(0, current);

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
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends