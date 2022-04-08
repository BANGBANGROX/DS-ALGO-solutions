// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int countSquare(int b) {
        // code here 
        return ((b / 2 - 1) + (b / 2 - 1) - 1 + (b / 2 - 3) * (b / 2 - 2) / 2);
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int B, count;
        cin >> B;
        Solution ob;
        count = ob.countSquare(B);
        cout << count << endl;
    }
}  // } Driver Code Ends