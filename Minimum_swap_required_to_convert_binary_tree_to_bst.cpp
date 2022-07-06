// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
	void inorderTraversal(vector<int>& tree, int index, vector<int>& res) {
		if (index >= (int)tree.size()) return;

		inorderTraversal(tree, 2 * index + 1, res);
	    
		res.push_back(tree[index]);

		inorderTraversal(tree, 2 * index + 2, res);
	}

public:
	int minSwaps(vector<int>& tree, int n) {
		//Write your code here
		vector<int> inorder;
		vector<vector<int>> numWithIndex(n);
		int ans = 0;

		inorderTraversal(tree, 0, inorder);

		for (int i = 0; i < n; ++i) {
			numWithIndex[i] = { inorder[i], i };
		}

		sort(numWithIndex.begin(), numWithIndex.end());

		for (int i = 0; i < n; ++i) {
			if (numWithIndex[i][1] == i) continue;
			swap(numWithIndex[i], numWithIndex[numWithIndex[i][1]]);
			++ans;
			--i;
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
		int n;
		cin >> n;
		vector<int>A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		Solution ob;
		int ans = ob.minSwaps(A, n);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends