// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution {

public:

	int digitSum(int n) {
		int res = 0;

		while (n) {
			res += n % 10;
			n /= 10;
		}

		return res;
	}

	pair<int, int> firstSecondMax(vector<int>& a) {
		int firstMax = 0, secondMax = 0;

		for (int y : a) {
			if (y > firstMax) {
				secondMax = firstMax;
				firstMax = y;
			}
			else if (y > secondMax && y <= firstMax) {
				secondMax = y;
			}
		}

		return { firstMax,secondMax };
	}

	int RulingPair(vector<int>& a, int n) {
		// Your code goes here
		unordered_map<int, vector<int>> mp;
		int ans = -1;

		for (int i = 0; i < n; ++i) {
			int sum = digitSum(a[i]);
			mp[sum].push_back(a[i]);
		}

		for (pair<int, vector<int>> x : mp) {
			if (x.second.size() < 2) continue;
			pair<int, int> maxElements = firstSecondMax(x.second);
			ans = max(maxElements.first + maxElements.second, ans);
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution obj;
		cout << obj.RulingPair(arr, n) << "\n";
	}
	return 0;
}

// } Driver Code Ends