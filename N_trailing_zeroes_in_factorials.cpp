//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int countFives(int num) {
        int result = 0;

        for (int i = 5; num / i > 0; i *= 5) {
            result += num / i;
        }

        return result;
    }

public:
    int countZeroes(int n) {
        // Code here
        int l = 0;
        int r = n * 5;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            int cnt = countFives(mid);
            if (cnt == n) return 5;
            if (cnt > n) r = mid - 1;
            else l = mid + 1;
        }

        return 0;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    	 int n;
    	 cin>>n;
    	 Solution obj;
    	 cout << obj.countZeroes(n);
    	 cout <<endl;
	}
	return 0;
}


// } Driver Code Ends