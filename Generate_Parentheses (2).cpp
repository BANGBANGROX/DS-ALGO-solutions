//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
	vector<string> ans;
	int n;

	void generate(int openCount,int closeCount, string& current) {
		if ((int)current.size() == 2 * n && openCount == closeCount) {
			ans.push_back(current);
			return;
		}

		if (openCount < n) {
			current.push_back('(');
			generate(openCount + 1, closeCount, current);
			current.pop_back();
		}

		if (closeCount < n && closeCount < openCount) {
			current.push_back(')');
			generate(openCount, closeCount + 1, current);
			current.pop_back();
		}
	}

public:
	vector<string> AllParenthesis(int n) {
		// Your code goes here 
		string current("");
		this->n = n;

		generate(0, 0, current);

		return ans;
	}
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << "\n";
	}
	return 0;
}

// } Driver Code Ends