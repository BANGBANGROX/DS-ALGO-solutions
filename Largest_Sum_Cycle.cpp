//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    typedef long long ll;

    vector<int> edge;
    vector<bool> recStack;
    vector<bool> visited;
    ll ans;

    void dfs(int node) {
        visited[node] = recStack[node] = true;
        int child = edge[node];

        if (child == -1) {
            recStack[node] = false;
            return;
        }

        if (!visited[child]) {
            dfs(child);
        }
        else if (recStack[child]) {
            ll current = 0;
            int temp = child;
            do {
                current += temp;
                temp = edge[temp];
            } while (temp != child);
            ans = max(ans, current);
        }

        recStack[node] = false;
    }

public:
    ll largestSumCycle(int n, vector<int>& edge) {
        // code here
        this->edge = edge;
        recStack = vector<bool>(n);
        visited = vector<bool>(n);
        ans = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        vector<int> Edge(N);
        for(int i=0;i<N;i++){
            cin>>Edge[i];
        }
        Solution obj;
        long long ans=obj.largestSumCycle(N, Edge);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends