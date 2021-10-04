#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int countOccurence(int a[], int n, int k) {
    unordered_map<int, int> freq;
    unordered_map<int, bool> vis;
    int threshold = n / k, res = 0;
    for (int i = 0; i < n; ++i) ++freq[a[i]];

    for (int i = 0; i < n; ++i) {
        if (freq[a[i]] > threshold) {
            if (vis.find(a[i]) == vis.end()) {
                vis[a[i]] = true;
                ++res;
            }
        }
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int* a = new int[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        cout << countOccurence(a, n, k) << endl;
    }

    return 0;
}