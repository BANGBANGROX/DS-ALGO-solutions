// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string UncommonChars(string s, string t) {
        // code here
        string ans("");
        unordered_set<char> characters;
        unordered_set<char> sSet(s.begin(), s.end());
        unordered_set<char> tSet(t.begin(), t.end());

        for (char ch : sSet) {
            characters.insert(ch);
        }

        for (char ch : tSet) {
            if (characters.find(ch) == characters.end()) {
                characters.insert(ch);
            }
            else {
                characters.erase(ch);
            }
        }

        for (char ch : characters) {
            ans += ch;
        }

        if (ans.empty()) return "-1";

        sort(ans.begin(), ans.end());

        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends