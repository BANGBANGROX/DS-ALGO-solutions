// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
private:
    int compute(int a, int b, char operation) {
        if (operation == '+') return a + b;

        if (operation == '-') return a - b;

        if (operation == '*') return a * b;

        return a / b;
    }

public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s) {
        // Your code here
        stack<int> st;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                st.push(s[i] - '0');
                continue;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(compute(a, b, s[i]));
        }

        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}
// } Driver Code Ends