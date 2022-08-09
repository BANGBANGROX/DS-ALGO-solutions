//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string Reduced_String(int k, string s) {
        // Your code goes here
        string ans("");
        stack<pair<char, int>> st;

        if (k == 1) return ans;

        for (char ch : s) {
            if (st.empty()) {
                st.push({ ch,1 });
                continue;
            }
            if (ch == st.top().first) {
                int cnt = st.top().second + 1;
                if (cnt == k) {
                    while (!st.empty() && ch == st.top().first) {
                        st.pop();
                    }
                }
                else st.push({ ch,cnt });
            }
            else st.push({ ch, 1 });
        }

        while (!st.empty()) {
            ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main() {


    int t; cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.Reduced_String(k, s) << "\n";

    }

    return 0;
}
// } Driver Code Ends