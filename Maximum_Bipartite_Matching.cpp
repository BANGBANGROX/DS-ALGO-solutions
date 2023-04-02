//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<bool> jobTaken;
    vector<int> jobApplicant;
    vector<vector<int>> graph;
    int n;

    bool dfs(int node) {
        for (int i = 0; i < n; ++i) {
            if (graph[node][i] == 1 && !jobTaken[i]) {
                jobTaken[i] = true;
                if (jobApplicant[i] == -1 || dfs(jobApplicant[i])) {
                    jobApplicant[i] = node;
                    return true;
                }
            }
        }

        return false;
    }


public:
	int maximumMatch(vector<vector<int>>& graph){
	    // Code here
        int m = (int) graph.size();
        n = (int) graph[0].size();
        this->graph = graph;
        jobApplicant = vector<int>(n, -1);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            jobTaken = vector<bool>(n);
            if (dfs(i)) {
                ++ans;
            }
        }

        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends