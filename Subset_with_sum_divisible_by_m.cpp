//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int DivisibleByM(vector<int>& nums, int m){
        // Code here
        vector<bool> previousState(m);

        for (int num : nums) {
            vector<bool> nextState(m);
            nextState[num % m] = true;
            for (int i = 0; i < m; ++i) {
                if (previousState[i]) nextState[(i + num) % m] = true;
                nextState[i] = nextState[i] | previousState[i];
            }
            previousState = nextState;
        }

        return previousState[0];
    }
};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution ob;
        int ans  = ob.DivisibleByM(nums, m);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends