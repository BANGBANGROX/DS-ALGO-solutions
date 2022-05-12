// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>>& arr, int n);


int main() {

    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }

        vector<int> ans;
        ans = permute(arr, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << "\n";

    }

    return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>>& nums, int n) {
    // Complete the function
    vector<pair<int, int>> indexedTime(n);
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        int startTime = nums[i][0];
        int burstTime = nums[i][1];
        indexedTime[i] = { startTime + burstTime,i };
    }

    sort(indexedTime.begin(), indexedTime.end());

    for (int i = 0; i < n; ++i) {
        ans.push_back(indexedTime[i].second);
    }

    return ans;
}