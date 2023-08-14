//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int m = (int)heights.size();
        int n = (int)heights[0].size();
        vector<vector<int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        set<vector<int>> st;

        st.insert({ 0, 0, 0 });
        distance[0][0] = 0;

        while (!st.empty()) {
            vector<int> cell = *st.begin();
            st.erase(cell);
            if (cell[0] > distance[cell[1]][cell[2]]) continue;
            for (vector<int>& direction : directions) {
                int newX = cell[1] + direction[0];
                int newY = cell[2] + direction[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int dis = max(cell[0], abs(heights[newX][newY] -
                        heights[cell[1]][cell[2]]));
                    if (distance[newX][newY] > dis) {
                        distance[newX][newY] = dis;
                        st.insert({ dis,newX,newY });
                    }
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends