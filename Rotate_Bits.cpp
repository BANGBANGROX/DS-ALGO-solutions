// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector <int> rotate(int n, int d)
    {
        //code here.
        int bit = 16;

        if (d > 16) {
            d %= 16;
        }

        int x = (n << d) | (n >> (bit - d));
        int y = (n >> d) | (n << (bit - d));

        return { x & 65535, y & 65535 };
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {

        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate(n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends