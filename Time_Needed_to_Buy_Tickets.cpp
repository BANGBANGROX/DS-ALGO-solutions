#include<bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0, val = tickets[k], n = tickets.size();

    for (int i = 0; i < n; ++i) {
        if (i <= k) ans += min(tickets[i], val);
        else ans += min(tickets[i], val - 1);
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;
        vector<int> tickets(n);
        for (int& x : tickets) cin >> x;
        cin >> k;

        cout << timeRequiredToBuy(tickets, k) << endl;
    }

    return 0;
}