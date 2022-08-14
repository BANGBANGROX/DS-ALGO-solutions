//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital) {
        //code here
        int m = hospital.size();
        int n = hospital[0].size();
        int ans = 0;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        queue<vector<int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (hospital[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<int> cell = q.front();
                q.pop();
                int x = cell[0];
                int y = cell[1];
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX >= 0 && newY >= 0 && newX < m && newY < n && hospital[newX][newY] == 1) {
                        hospital[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            ++ans;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (hospital[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int>> hospital;
        int i, j;
        for (i = 0; i < R; i++) {
            vector<int> temp;
            for (j = 0; j < C; j++) {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends