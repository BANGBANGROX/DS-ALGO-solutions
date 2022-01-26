// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    bool checkWeight(int a[], int weight, int D, int n) {
        int days = 1;
        int currentWeight = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] > weight) return false;
            currentWeight += a[i];
            if (currentWeight > weight) {
                ++days;
                if (days > D) return false;
                currentWeight = a[i];
            }
        }

        return true;
    }

public:
    int leastWeightCapacity(int a[], int n, int D) {
        // code here
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        int low = 1;
        int high = sum;

        while (low < high) {
            int mid = (low + ((high - low) >> 1));
            if (checkWeight(a, mid, D, n)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int* arr = new int[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}  // } Driver Code Ends