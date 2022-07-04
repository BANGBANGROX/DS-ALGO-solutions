// { Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    unordered_set<string> dictionary;
    vector<vector<string>> ans;
    string s;
    int n;
 
    void generate(int index, vector<string>& current, string currentString) {
        if (index == n) {
            if (dictionary.find(currentString) != dictionary.end()) {
                current.push_back(currentString);
                ans.push_back(current);
                current.pop_back();
            }
            return;
        }

        currentString += s[index];

        generate(index + 1, current, currentString);

        if (dictionary.find(currentString) != dictionary.end()) {
            current.push_back(currentString);
            generate(index + 1, current, "");
            current.pop_back();
        }

        currentString.pop_back();
    }

public:
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        // code here
        dictionary = unordered_set<string>(dict.begin(), dict.end());
        this->s = s;
        this->n = s.size();
        string currentString("");
        vector<string> current;

        generate(0, current, currentString);

        vector<string> result;

        for (vector<string>& x : ans) {
            string y("");
            for (string& z : x) {
                if (!y.empty()) y = y + ' ' + z;
                else y += z;
            }
            result.push_back(y);
        }

        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends