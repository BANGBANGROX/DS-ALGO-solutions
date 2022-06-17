// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
	typedef long long ll;
public:
	// X[], Y[]: input arrau
	// M, N: size of arrays X[] and Y[] respectively
	//Function to count number of pairs such that x^y is greater than y^x.
	ll countPairs(int nums1[], int nums2[], int m, int n) {
		ll ans = 0;
		int onesCount = 0;
		int twosCount = 0;
		int foursCount = 0;
		int threesCount = 0;

		for (int i = 0; i < n; ++i) {
			if (nums2[i] == 1) ++onesCount;
			if (nums2[i] == 2) ++twosCount;
			if (nums2[i] == 3) ++threesCount;
			if (nums2[i] == 4) ++foursCount;
		}

		sort(nums2, nums2 + n);

		for (int i = 0; i < m; ++i) {
			if (nums1[i] == 1) continue;
			int idx = upper_bound(nums2, nums2 + n, nums1[i]) - nums2;
			ans += ((ll)n - idx);
			ans += onesCount;
			if (nums1[i] == 2) {
				ans -= ((ll)threesCount + foursCount);
			}
			if (nums1[i] == 3) ans += (ll)twosCount;
		}

		return ans;
	}
};


// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N;
		cin >> M >> N;
		int i, * a = new int[M], * b = new int[N];
		for (i = 0; i < M; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < N; i++)
		{
			cin >> b[i];
		}
		Solution ob;
		cout << ob.countPairs(a, b, M, N) << endl;
	}
}  // } Driver Code Ends