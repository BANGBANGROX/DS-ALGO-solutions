// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
    vector<string> ans;

    void generateIPV4Adresses(string& s, int index, string current, int dots) {
        int n = s.size();

        if (dots == 0) {
            string last = s.substr(index);
            if (n - index > 3 || stoi(last) > 255 || (last != "0" && last[0] == '0')) return;
            current += s.substr(index);
            ans.push_back(current);
            return;
        }

        string num("");

        for (int i = index; i < n - dots; ++i) {
            num += s[i];
            if (stoi(num) > 255 || (num != "0" && num[0] == '0')) break;
            generateIPV4Adresses(s, i + 1, current + num + ".", dots - 1);
        }
    }

public:
    vector<string> genIp(string& s) {
        // Your code here
        string current("");

        generateIPV4Adresses(s, 0, current, 3);

        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else {
            for (auto& u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends