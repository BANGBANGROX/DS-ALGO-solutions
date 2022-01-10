// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Returns area of the largest rectangle of 1's
    int maxArea(vector<bool> mat[], int r, int c) {
        // code here
        vector<vector<int>> hist(r + 1, vector<int>(c + 1));
        int maxArea = 0;

        // Compute hist
        for (int i = 0; i < c; ++i) {
            hist[0][i] = mat[0][i];
            for (int j = 1; j < r; ++j) {
                hist[j][i] = (mat[j][i] == 0) ? 0 : hist[j - 1][i] + 1;
            }
        }

        // Sort hist based on coloums
        for (int i = 0; i < r; ++i) {
            vector<int> count(r + 1);
            for (int j = 0; j < c; ++j) {
                ++count[hist[i][j]];
            }
            int colNo = 0;
            for (int j = r; j >= 0; --j) {
                if (count[j] > 0) {
                    for (int k = 0; k < count[j]; ++k) {
                        hist[i][colNo] = j;
                        ++colNo;
                    }
                }
            }
        }

        // Find maximum area
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                maxArea = max(maxArea, (j + 1) * hist[i][j]);
            }
        }

        return maxArea;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool>* mat = new vector<bool>[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}
// } Driver Code Ends