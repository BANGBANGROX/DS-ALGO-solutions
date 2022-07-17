//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution {
    bool isKPartitionPossibleUtil(int nums[], int n, int k, int subsetSum, int currentSum, 
        int index, vector<bool>&visited) {
        if (k == 1) return true;

        if (currentSum == subsetSum) {
            return isKPartitionPossibleUtil(nums, n, k - 1, subsetSum, 0, 0, visited);
        }

        for (int i = index; i < n; ++i) {
            if (visited[i] || currentSum + nums[i] > subsetSum) continue;
            currentSum += nums[i];
            visited[i] = true;
            if (isKPartitionPossibleUtil(nums, n, k, subsetSum, currentSum, i + 1, visited)) 
                return true;
            currentSum -= nums[i];
            visited[i] = false;
        }

        return false;
    }

public:
    bool isKPartitionPossible(int nums[], int n, int k) {
        //Your code here
        int totalSum = accumulate(nums, nums + n, 0);

        if (totalSum % k != 0) return false;

        vector<bool> visited(n);
        int subsetSum = totalSum / k;
        int index = 0;
        int currentSum = nums[index];
        visited[index] = true;

        return isKPartitionPossibleUtil(nums, n, k, subsetSum, currentSum, index, visited);
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
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
}
// } Driver Code Ends