//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
    //Complete the function and return minimum number of operations
public:
    int specialPalindrome(string s1, string s2) {
        //Code Here
        int m = (int) s1.size();
        int n = (int) s2.size();
        int ans = INT_MAX;

        for (int i = 0; i <= m - n; ++i) {
            int currentCost = 0;
            for (int j = 0; j < n; ++j) {
                if (s1[i + j] != s2[j]) {
                    ++currentCost;
                }
            }
            int l = 0;
            int r = m - 1;
            while (l < r) {
                if (i <= l && l < i + n && i <= r && r < i + n
                && s2[l - i] != s2[r - i]) {
                    break;
                }
                char left = s1[l];
                char right = s1[r];
                if (i <= l && l < i + n) {
                    left = s2[l - i];
                }
                if (i <= r && r < i + n) {
                    right = s2[r - i];
                }
                if (left != right) {
                    ++currentCost;
                }
                ++l;
                --r;
            }
            if (l >= r) {
                ans = min(ans, currentCost);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends