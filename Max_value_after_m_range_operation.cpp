//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;

	public:
	int findMax(int n, int m, int a[], int b[], int k[]) {
	    // Your code goes here
        vector<ll> aux(n + 1);

        for (int i = 0; i < m; ++i) {
            int l = a[i];
            int r = b[i];
            int val = k[i];
            aux[l] += val;
            aux[r + 1] -= val;
        }

        for (int i = 1; i <= n; ++i) {
            aux[i] += aux[i - 1];
        }

        return *max_element(aux.begin(), aux.begin() + n);
	}
};

//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[m],b[m],k[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i]>>b[i]>>k[i];
        }
       

        Solution ob;
        cout <<  ob.findMax(n, m, a, b, k);
	    cout << "\n";
	     
    }
    return 0;
}




// } Driver Code Ends