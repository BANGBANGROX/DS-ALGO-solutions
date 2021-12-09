#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& colors) {
    int n = colors.size(), col = colors[0], pos = INT_MAX, maxDist = 1;

    for (int i = 1; i < n; ++i) {
        if (colors[i] != col) pos = min(pos, i);
        maxDist = max({ maxDist, colors[i] == col ? 0 : i, i - pos });
    }

    return maxDist;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> colors(n);
        for (int& x : colors) cin >> x;

        cout << maxDistance(colors) << endl;
    }

    return 0;
}
