// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int countDistinctSubarray(int arr[], int n) {
		//code here.
		unordered_map<int, int> count;
		int ans = 0;
		int l = 0;
		int needed = 0;
		int completed = 0;

		for (int i = 0; i < n; ++i) {
			if (count.find(arr[i]) == count.end()) ++needed;
			++count[arr[i]];
		}

		count.clear();

		for (int r = 0; r < n; ++r) {
			++count[arr[r]];
			if (count[arr[r]] == 1) ++completed;
			if (completed == needed) {
				while (count[arr[l]] > 1) {
					--count[arr[l]];
					++l;
					ans += (n - r);
				}
				++ans;
			}
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
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		Solution ob;
		cout << ob.countDistinctSubarray(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends