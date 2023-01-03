//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minCount(int nums[], int n) {
        // Your code goes here
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(n + 2,
                                               vector<int>(n + 2)));

        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n + 1; ++j) {
                for (int k = 1; k <= n + 1; ++k) {
                    if (i > 0) {
                        dp[i][j][k] = dp[i - 1][j][k];
                        if (j == n + 1 || nums[i - 1] < nums[j - 1]) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][i][k] + 1);
                        }
                        if (k == n + 1 || nums[i - 1] > nums[k - 1]) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][i] + 1);
                        }
                    }
                }
            }
        }

        return n - dp[n][n + 1][n + 1];
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minCount(a, n) << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends//{ Driver Code Starts
//#include <bits/stdc++.h>
//using namespace std;
//
//// } Driver Code Ends
//class Solution{
//
//	public:
//	int minCount(int arr[], int N)
//	{
//        // Your code goes here
//	}
//};
//
//
////{ Driver Code Starts.
//int main()
//{
//
//
//   	int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//
//        int a[n];
//
//        for(int i = 0; i < n; i++)
//        	cin >> a[i];
//
//
//
//	    Solution ob;
//	    cout << ob.minCount(a, n) << "\n";
//
//    }
//    return 0;
//}
//
//
//
//// } Driver Code Ends