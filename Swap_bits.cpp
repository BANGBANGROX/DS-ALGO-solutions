// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	int swapBits(int x, int p1, int p2, int n) {
		int ans = x;

		for (int i = p1, j = p2; i < p1 + n; ++i, ++j) {
			int bit1 = (x & (1 << i));
			int bit2 = (x & (1 << j));
			if (bit1 > 0 && bit2 > 0 || (bit1 == 0 && bit2 == 0)) continue;
			if (bit1 == 0) {
				ans -= (1 << j);
				ans += (1 << i);
			}
			else {
				ans -= (1 << i);
				ans += (1 << j);
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
		int x, p1, p2, n;
		cin >> x >> p1 >> p2 >> n;
		Solution obj;
		int res = obj.swapBits(x, p1, p2, n);
		printf("%d\n", res);
	}
	return 0;
}  // } Driver Code Ends