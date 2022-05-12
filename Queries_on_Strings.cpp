// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string s, vector<vector<int>>& queries) {
		// Code here
		vector<vector<int>> indexes(26);
		vector<int> ans;
		int n = s.size();
		
		for (int i = 0; i < n; ++i) {
			indexes[s[i] - 'a'].push_back(i);
		}

		for (const vector<int>& query : queries) {
			int l = query[0];
			int r = query[1];
			int res = 0;
			for (int i = 0; i < 26; ++i) {
				int idx = lower_bound(indexes[i].begin(), indexes[i].end(), l) - indexes[i].begin();
				if (idx < indexes[i].size() && indexes[i][idx] <= r) ++res;
			}
			ans.push_back(res);
		}

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			Query.push_back({ l, r });
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for (auto i : ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends