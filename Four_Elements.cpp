// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, x;
        cin >> n;
        int* a = new int[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int a[], int n, int sum) {
    sort(a, a + n);

    for (int i = 0; i < n - 3; ++i) {
        if (a[i] > sum) break;
        int oneSum = sum - a[i];
        for (int j = i + 1; j < n - 2; ++j) {
            if (a[j] > oneSum) break;
            int twoSum = oneSum - a[j];
            int l = j + 1, r = n - 1;
            while (l < r) {
                int threeSum = a[l] + a[r];
                if (threeSum == twoSum) return true;
                else if (threeSum > twoSum) --r;
                else ++l;
            }
        }
    }

    return false;
}
