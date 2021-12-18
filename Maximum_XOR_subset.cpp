// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    const int INT_BITS = 32;

    int maxXor(int a[], int n) {
        // Your code goes here
        int index = 0, res = 0;

        for (int bit = INT_BITS - 1; bit > -1; --bit) {
            int maxVal = INT_MIN, maxInd = index;
            for (int i = index; i < n; ++i) {
                if ((a[i] & (1 << bit)) != 0 && a[i] > maxVal) {
                    maxVal = a[i];
                    maxInd = i;
                }
            }
            if (maxVal == INT_MIN) continue;
            swap(a[index], a[maxInd]);
            maxInd = index;
            ++index;
            for (int i = 0; i < n; ++i) {
                if (i != maxInd && (a[i] & (1 << bit)) != 0) a[i] = a[i] ^ a[maxInd];
            }
        }

        for (int i = 0; i < n; ++i) {
            res = res ^ a[i];
        }

        return res;
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

        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxXor(a, n) << "\n";

    }
    return 0;
}
// } Driver Code Ends