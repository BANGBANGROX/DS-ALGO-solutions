//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n) {
        // Code here
        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int ans = 0;
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n));

        --knightPos[0];
        --knightPos[1];
        --targetPos[0];
        --targetPos[1];

        if (knightPos[0] == targetPos[0] && targetPos[1] == knightPos[1]) return 0;

        q.push({knightPos[0], knightPos[1]});
        visited[knightPos[0]][knightPos[1]] = true;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                if (x == targetPos[0] && y == targetPos[1]) return ans;
                for (int j = 0; j < 8; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                        !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends