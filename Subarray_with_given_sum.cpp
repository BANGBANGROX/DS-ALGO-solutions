// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s) {
        // Your code here
        ll sum = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            sum += arr[r];
            while (sum > s) {
                sum -= arr[l];
                ++l;
            }
            if (sum == s) return { l + 1,r + 1 };
        }

        return { -1 };
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int* arr = new int[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }
    return 0;
}  // } Driver Code Ends