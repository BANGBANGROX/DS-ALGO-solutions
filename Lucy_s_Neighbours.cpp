// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	vector<int> Kclosest(vector<int>houseNo, int n, int x, int k) {
		// Your code goes here 
		vector<pair<int, int>> distances(n);
		vector<int> ans(k);

		for (int i = 0; i < n; ++i)  distances[i] = { abs(x - houseNo[i]),houseNo[i] };

		sort(distances.begin(), distances.end());

		for (int i = 0; i < k; ++i) ans[i] = distances[i].second;

		sort(ans.begin(), ans.end());

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
		int n, x, k;
		cin >> n >> x >> k;
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin >> array[i];

		Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k);
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}



// } Driver Code Ends
