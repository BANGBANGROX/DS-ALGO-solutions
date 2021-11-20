#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size(), buy = -1 * prices[0], sell = 0;

    for (int i = 1; i < n; ++i) {
        buy = max(buy, sell - prices[i]);
        sell = max(prices[i] + buy - fee, sell);
    }

    return max(buy, sell);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, fee;
        cin >> n;
        vector<int> prices(n);
        for (int& x : prices) cin >> x;
        cin >> fee;

        cout << maxProfit(prices, fee) << endl;
    }

    return 0;
}