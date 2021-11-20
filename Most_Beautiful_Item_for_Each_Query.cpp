#include<bits/stdc++.h>
using namespace std;

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    map<int, int> mp;
    vector<int> ans;

    for (vector<int> item : items) {
        int price = item[0], beauty = item[1];
        if (mp.find(price) == mp.end()) mp[price] = beauty;
        else mp[price] = max(mp[price], beauty);
    }

    auto it1 = mp.begin(), it2 = it1;
    ++it2;

    for (; it2 != mp.end(); ++it2) {
        it2->second = max(it1->second, it2->second);
        ++it1;
    }

    for (int q : queries) {
        auto it = mp.upper_bound(q);
        if (it == mp.begin()) {
            ans.push_back(0);
            continue;
        }
        else --it;
        ans.push_back(it->second);
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n;
        vector<vector<int>> items(n);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            items[i] = { a,b };
        }
        cin >> q;
        vector<int> queries(q);
        for (int& x : queries) cin >> x;

        vector<int> ans = maximumBeauty(items, queries);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
