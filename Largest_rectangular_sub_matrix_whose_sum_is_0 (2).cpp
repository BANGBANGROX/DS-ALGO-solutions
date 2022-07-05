// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<int> maxLengthZeroSumSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxLen = 0;
        int start = -1;
        int end = -1;
        unordered_map<int, int> sumIndex;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (nums[i] == 0 && maxLen == 0) {
                start = i;
                end = i;
            }
            if (sum == 0) {
                maxLen = i + 1;
                start = 0;
                end = i;
            }
            if (sumIndex.find(sum) != sumIndex.end()) {
                if (i - sumIndex[sum] > maxLen) {
                    start = sumIndex[sum] + 1;
                    end = i;
                    maxLen = end - start + 1;
                }
            }
            else sumIndex[sum] = i;
        }

        return { start,end };
    }

public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>& matrix) {
        //Code Here
        int m = matrix.size();
        int n = matrix[0].size();
        int startCol = -1;
        int endCol = -1;
        int startRow = -1;
        int endRow = -1;
        int maxArea = 0;
        vector<vector<int>> ans;
        
        for (int left = 0; left < n; ++left) {
            vector<int> nums(m);
            for (int right = left; right < n; ++right) {
                for (int i = 0; i < m; ++i) {
                    nums[i] += matrix[i][right];
                }
                vector<int> topBottom = maxLengthZeroSumSubarray(nums);
                int top = topBottom[0];
                int bottom = topBottom[1];
                if (top == -1) continue;
                int length = (right - left + 1);
                int width = (bottom - top + 1);
                if (maxArea < length * width) {
                    startCol = left;
                    endCol = right;
                    startRow = top;
                    endRow = bottom;
                    maxArea = length * width;
                }
            }
        }

        if (startRow == -1) return ans;

        ans = vector<vector<int>>((endRow - startRow + 1), vector<int>(endCol - startCol + 1));

        for (int i = startRow; i <= endRow; ++i) {
            for (int j = startCol; j <= endCol; ++j) {
                ans[i - startRow][j-startCol] = matrix[i][j];
            }
        }

        return ans;
    }
};


// { Driver Code Starts.




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if (ans.size() == 0) {
            cout << -1 << endl;
        }
        else {
            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < ans[0].size(); j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}  // } Driver Code Ends