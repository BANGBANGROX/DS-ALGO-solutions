//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n) {
        // your code here
        string lowerChars("");
        string upperChars("");
        string ans("");

        for (char ch : s) {
            if (islower(ch)) lowerChars += ch;
            else upperChars += ch;
        }

        sort(lowerChars.begin(), lowerChars.end());
        sort(upperChars.begin(), upperChars.end());

        int i = 0;
        int j = 0;

        for (char ch : s) {
            if (islower(ch)) {
                ans += lowerChars[i];
                ++i;
            }
            else {
                ans += upperChars[j];
                ++j;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        Solution obj;
        cout<<obj.caseSort (str, n)<<endl;
    }
}
// } Driver Code Ends