// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

public:
	vector<int> help_classmate(vector<int> arr, int n) {
		// Your code goes here
		vector<int> res(n);
		stack<int> s;

		for (int i = n - 1; i > -1; --i) {
			while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
			res[i] = s.empty() ? -1 : arr[s.top()];
			s.push(i);
		}

		return res;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array, n);
		for (int i = 0; i < n; ++i)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends