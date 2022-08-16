//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> factorial;

    string generate(int n, int c) {
        if (n == 0) return "";

        if (factorial[c] > n) return generate(n, c - 1);

        return generate(n - factorial[c], c) + to_string(c);
    }

public:
    vector<int> FactDigit(int n) {
        // Code here
        factorial = vector<int>(10);
        factorial[0] = 1;

        for (int i = 1; i < 10; ++i) {
            factorial[i] = i * factorial[i - 1];
        }

        string result = generate(n, 9);
        vector<int> ans;

        for (char ch : result) {
            ans.push_back((ch - '0'));
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        Solution ob;
        vector<int>ans = ob.FactDigit(N);
        for(auto i: ans)
            cout << i;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends