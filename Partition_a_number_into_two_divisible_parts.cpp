// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string stringPartition(string s, int a, int b) {
        // code here
        int n = s.size();

        for (int len = 1; len < n; ++len) {
            string stringNum1 = s.substr(0, len);
            string stringNum2 = s.substr(len);
            int num1 = stoi(stringNum1);
            int num2 = stoi(stringNum2);
            if (num1 % a == 0 && num2 % b == 0) return stringNum1 + " " + stringNum2;
        }

        return "-1";
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S, a, b) << endl;
    }
    return 0;
}   // } Driver Code Ends