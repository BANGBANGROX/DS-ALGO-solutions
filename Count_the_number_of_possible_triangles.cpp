//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int nums[], int n) {
        // code here
        int ans = 0;

        sort(nums, nums + n);

        for (int i = n - 1; i > 1; --i) {
            int c = nums[i];
            int l = 0;
            int r = i - 1;
            while (l <= r) {
                int sum = nums[l] + nums[r];
                if (sum > c) {
                    ans += (r - l);
                    --r;
                }
                else ++l;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends