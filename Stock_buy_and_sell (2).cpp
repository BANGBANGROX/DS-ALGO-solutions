//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int*, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int* price = new int[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here

    if (n == 1) {
        cout << "No Profit" << endl;
        return;
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        int start = i;
        while (i + 1 < n && price[i + 1] > price[i]) ++i;
        if (start == i) continue;
        else ans.push_back({ start,i });
    }

    if (ans.empty()) {
        cout << "No Profit" << endl;
        return;
    }

    for (vector<int>& x : ans) {
        cout << "(" << x[0] << " " << x[1] << ") ";
    }

    cout << endl;
}