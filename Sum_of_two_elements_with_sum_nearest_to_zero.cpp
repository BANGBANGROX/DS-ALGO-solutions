// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int a[], int n) {
        // your code here 
        int minSum = INT_MAX, l = 0, r = n - 1;

        sort(a, a + n);

        while (l < r) {
            int sum = a[l] + a[r];
            if (abs(sum) < abs(minSum) || abs(sum) == abs(minSum) && sum > 0) {
                minSum = sum;
            }
            if (sum > 0) --r;
            else ++l;
        }

        return minSum;
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
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
