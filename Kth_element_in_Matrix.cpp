// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int mat[MAX][MAX];

int kthSmallest(int mat[MAX][MAX], int n, int k);

// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends


int findLessthanOrEqualTo(int m[MAX][MAX], int n, int key) {
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (m[i][0] > key) return ans;

        if (m[i][n - 1] <= key) {
            ans += n;
            continue;
        }

        int ind = 0;
        for (int jump = n / 2; jump > 0; jump /= 2) {
            while (ind + jump < n && m[i][ind + jump] <= key) {
                ind += jump;
            }
        }
        ans += (ind + 1);
    }

    return ans;
}

int kthSmallest(int m[MAX][MAX], int n, int k) {
    //Your code here
    int l = m[0][0], r = m[n - 1][n - 1];

    while (l <= r) {
        int mid = (l + r) / 2;
        int res = findLessthanOrEqualTo(m, n, mid);
        if (res >= k) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}

