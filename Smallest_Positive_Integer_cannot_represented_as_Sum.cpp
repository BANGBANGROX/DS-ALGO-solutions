//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    typedef long long ll;
public:
    ll smallestpositive(vector<ll>& nums, int n) {
        // code here 
        ll ans = 1;

        sort(nums.begin(), nums.end());

        for (ll num : nums) {
            if (ans < num) return ans;
            else ans += num;
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        Solution ob;
        cout << ob.smallestpositive(array, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends