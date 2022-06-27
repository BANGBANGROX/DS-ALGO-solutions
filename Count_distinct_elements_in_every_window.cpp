// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



// } Driver Code Ends

class Solution {
public:
    vector <int> countDistinct(int nums[], int n, int k) {
        //code here.
        unordered_map<int, int> count;
        vector<int> ans;
        int initialResult = 0;
        int l = 0;
        int r = k - 1;

        for (int i = 0; i < k; ++i) {
            if (count.find(nums[i]) == count.end()) {
                ++initialResult;
                count[nums[i]] = 0;
            }
            ++count[nums[i]];
        }

        while (r < n) {
            ans.push_back(initialResult);
            --count[nums[l]];
            if (count[nums[l]] == 0) --initialResult;
            ++l;
            ++r;
            if (r < n) {
                ++count[nums[r]];
                if (count[nums[r]] == 1) ++initialResult;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends