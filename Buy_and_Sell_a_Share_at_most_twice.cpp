// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>& price) {
    //Write your code here..
    int n = price.size();
    int profit1 = 0;
    int profit2 = 0;
    int minPrice1 = price[0];
    int minPrice2 = price[0];

    for (int i = 1; i < n; ++i) {
        minPrice1 = min(minPrice1, price[i]);
        profit1 = max(profit1, price[i] - minPrice1);
        minPrice2 = min(minPrice2, price[i] - profit1);
        profit2 = max(profit2, price[i] - minPrice2);
    }

    return profit2;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++) cin >> price[i];
        cout << maxProfit(price) << endl;
    }

}
// } Driver Code Ends