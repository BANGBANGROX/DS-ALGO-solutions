//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int characterReplacement(string s, int k) {
		// Code here
		int n = (int)s.size();
		int l = 0;
		int maxChars = 0;
		int ans = 0;
		vector<int> count(26);

		for (int r = 0; r < n; ++r) {
			++count[s[r] - 'A'];
			maxChars = max(maxChars, count[s[r] - 'A']);
			int differentChars = r - l + 1 - maxChars;
			if (differentChars > k) {
				--count[s[l] - 'A'];
				++l;
			}
			ans = max(ans, r - l + 1);
		}

		return ans;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends