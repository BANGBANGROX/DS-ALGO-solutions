// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int minimumCostOfBreaking(vector<int>& horizontalCost, vector<int>& verticalCost, int M, int N) {
		//Write your code here
		int ans = 0;
		int horizontalPieces = 1;
		int verticalPieces = 1;
		int m = horizontalCost.size();
		int n = verticalCost.size();
		int i = 0;
		int j = 0;

		sort(horizontalCost.begin(), horizontalCost.end(), greater<int>());
		sort(verticalCost.begin(), verticalCost.end(), greater<int>());

		while (i < m && j < n) {
			if (horizontalCost[i] < verticalCost[j]) {
				ans += verticalCost[j] * horizontalPieces;
				++verticalPieces;
				++j;
			}
			else {
				ans += horizontalCost[i] * verticalPieces;
				++horizontalPieces;
				++i;
			}
		}

		while (i < m) {
			ans += horizontalCost[i] * verticalPieces;
			++i;
		}

		while(j < n) {
			ans += verticalCost[j] * horizontalPieces;
			++j;
		}

		return ans;
	}
};



// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		vector<int>X(m - 1), Y(n - 1);
		for (int i = 0; i < m - 1; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> Y[i];
		}
		Solution ob;
		int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends