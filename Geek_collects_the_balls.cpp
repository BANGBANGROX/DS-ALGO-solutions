// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxBalls(int m, int n, vector<int>& a, vector<int>& b) {
        // code here
        int aSum = 0;
        int bSum = 0;
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                aSum += a[i];
                ++i;
            }
            else if (a[i] > b[j]) {
                bSum += b[j];
                ++j;
            }
            else {
                int common = a[i];
                int countA = 0;
                int countB = 0;
                while (i < m && a[i] == common) {
                    ++i;
                    ++countA;
                }
                while (j < n && b[j] == common) {
                    ++j;
                    ++countB;
                }
                int tempASum = max(aSum + countA * common, bSum + (countA + countB - 1) * common);
                int tempBSum = max(bSum + countB * common, aSum + (countA + countB - 1) * common);
                if (countA > 1 && countB > 1) {
                    tempASum = max(tempASum, aSum + (countA + countB - 2) * common);
                    tempBSum = max(tempBSum, bSum + (countA + countB - 2) * common);
                }
                aSum = tempASum;
                bSum = tempBSum;
            }
        }

        while (i < m) {
            aSum += a[i];
            ++i;
        }

        while (j < n) {
            bSum += b[j];
            ++j;
        }

        return max(aSum, bSum);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(M);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";
    }
    return 0;
}  // } Driver Code Ends