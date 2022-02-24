// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* a = new int[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

int lesserOrEqual(int a[], int n, int difference) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int num = a[i] + difference;
        int ind = upper_bound(a + i, a + n, num) - (a + i + 1);
        count += ind;
    }

    return count;
}

int kthDiff(int a[], int n, int k) {
    sort(a, a + n);

    int l = 0;
    int r = a[n - 1] - a[0];

    while (l < r) {
        int mid = (l + ((r - l) >> 1));
        int count = lesserOrEqual(a, n, mid);
        // cout << mid << " " << count << endl;
        if (count >= k) r = mid;
        else l = mid + 1;
    }

    return l;
}