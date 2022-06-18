// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minThrow(int n, int arr[]) {
        // code here
        vector<int> jumps(31, -1);
        queue<int> q;
        vector<bool> visited(31);
        int ans = 0;

        for (int i = 0; i < 2 * n; i += 2) {
            jumps[arr[i]] = arr[i + 1];
        }

        q.push(1);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cell = q.front();
                q.pop();
                if (cell == 30) return ans;
                for (int j = 1; j < 7; ++j) {
                    if (visited[cell + j]) continue;
                    if (jumps[cell + j] != -1 && !visited[jumps[cell + j]]) {
                        q.push(jumps[cell + j]);
                        visited[cell + j] = visited[jumps[cell + j]] = true;
                    }
                    else q.push(cell + j);
                }
            }
            ++ans;
        }

        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int* arr = new int[2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    return 0;
}  // } Driver Code Ends