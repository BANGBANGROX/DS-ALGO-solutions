#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int numTilings(int n) {
    if (n <= 2) return n;

    vector<ll> f(n + 1), p(n + 1);

    f[1] = 1;
    f[2] = 2;
    p[2] = 1;

    for (int i = 3; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + 2 * p[i - 1]) % mod;
        p[i] = (p[i - 1] + f[i - 2]) % mod;
    }

    return f[n];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        cout << numTilings(n) << endl;
    }

    return 0;
}