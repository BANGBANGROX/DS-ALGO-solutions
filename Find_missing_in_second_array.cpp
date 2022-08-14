//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    vector<ll> findMissing(ll nums1[], ll nums2[], int n, int m) {
        // Your code goes here
        unordered_set<ll> inNums2(nums2, nums2 + m);
        vector<ll> ans;

        for (int i = 0; i < n; ++i) {
            if (inNums2.find(nums1[i]) == inNums2.end()) {
                ans.push_back(nums1[i]);
            }
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
        cin>>n;
        int m;
        cin>>m;
        long long a[n];
        long long b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        vector<long long> ans;


        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";


        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends