// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void insertBottom(stack<int>& s, int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }

        int top = s.top();
        s.pop();

        insertBottom(s, x);

        s.push(top);
    }

    void revereStack(stack<int>& s) {
        if (s.empty()) return;

        int x = s.top();
        s.pop();

        revereStack(s);

        insertBottom(s, x);
    }

public:
    vector<int> Reverse(stack<int>& s) {
        vector<int> ans;

        revereStack(s);

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans = ob.Reverse(St);
        for (int i = 0; i < N; i++) {
            cout << ans[i];
            if (i != N - 1) cout << " ";
        }
        cout << endl;
    }
}  // } Driver Code Ends