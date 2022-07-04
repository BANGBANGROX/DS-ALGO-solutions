// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;

        for (char ch : s) {
            if (ch != ')' && !(ch >= 'a' && ch <= 'z')) st.push(ch);
            else {
                bool isRedundant = false;
                if (st.top() == '(') {
                    return 1;
                }
                while (st.top() != '(') st.pop();
                st.top();
            }
        }

        return 0;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    scanf_s("%d", &t);
    while (t--) {


        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;

    }
}
// } Driver Code Ends