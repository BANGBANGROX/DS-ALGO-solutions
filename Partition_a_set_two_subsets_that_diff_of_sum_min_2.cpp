// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<bool> finallyTaken;
    vector<int> nums;
    int n;
    int totalSum;
    int minDiff;

    void generate(int index, int currentSum, vector<bool>& currentState, int currentlyTaken) {
        if (index == n) {
            if (n % 2 == 0 && currentlyTaken != n / 2 || 
                ((n % 2 == 1 && (currentlyTaken > (n + 1) / 2 || currentlyTaken < (n - 1) / 2)))) 
                return;
            if (minDiff > abs(currentSum - totalSum)) {
                finallyTaken = currentState;
                minDiff = abs(currentSum - totalSum);
            }
            return;
        }

        // Take the current element
        currentSum += nums[index];
        ++currentlyTaken;
        currentState[index] = true;

        generate(index + 1, currentSum, currentState, currentlyTaken);

        // Leave the current element
        currentSum -= nums[index];
        --currentlyTaken;
        currentState[index] = false;

        generate(index + 1, currentSum, currentState, currentlyTaken);
    }

public:
    vector<vector<int>> minDifference(vector<int>& nums, int n) {
        //Code here
        finallyTaken = vector<bool>(n);
        this->nums = nums;
        this->n = n;
        minDiff = INT_MAX;
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<bool> currentState(n);

        generate(0, 0, currentState, 0);

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            if (finallyTaken[i]) ans[0].push_back(nums[i]);
            else ans[1].push_back(nums[i]);
        }

        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<vector<int>> ans = obj.minDifference(arr, n);
        //printing S1 and S2 arrays
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}  // } Driver Code Ends