// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string previousNumber(string s) {
        // code here 
        int n = s.size();
        vector<int> index(10, -1);
        
        if (n == 1) return "-1";

        index[s[n - 1] - '0'] = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            int currentDigit = s[i] - '0';
            for (int dig = currentDigit - 1; dig >= 0; --dig) {
                if (index[dig] != -1 && !(s[index[dig]] == '0' && i == 0)) {
                    swap(s[i], s[index[dig]]);
                    return s;
                }
            }
            index[currentDigit] = i;
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0;
}   // } Driver Code Ends