// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T>& A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T>& A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (i != A.size() - 1) cout << A[i] << " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    vector<string> ans;
    unordered_set<string> visited;

    int getMinInvalid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') st.push(ch);
            else if (ch == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(ch);
            }
        }

        return st.size();
    }

    void generate(string s, int minInvalid) {
        if (visited.find(s) != visited.end()) return;

        visited.insert(s);

        if (minInvalid == 0) {
            if (getMinInvalid(s) == 0) {
                visited.insert(s);
                ans.push_back(s);
            }
            return;
        }

        for (int i = 0; i < (int)s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            generate(left + right, minInvalid - 1);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        // code here
        generate(s, getMinInvalid(s));

        sort(ans.begin(), ans.end());

        return ans;
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
        vector<string> res = obj.removeInvalidParentheses(s);

        Array::print(res);

    }
}
// } Driver Code Ends