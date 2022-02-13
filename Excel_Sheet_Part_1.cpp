// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    string letters[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V",
        "W","X","Y","Z" };
public:
    string ExcelColumn(int n) {
        // Your code goes here
        if (n == 0) return "Z";

        if (n <= 26) return letters[n - 1];

        if (n % 26 == 0) return ExcelColumn(n / 26 - 1) + "Z";

        return ExcelColumn(n / 26) + ExcelColumn(n % 26);
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
        Solution ob;
        cout << ob.ExcelColumn(n) << endl;
    }
    return 0;
}
// } Driver Code Ends