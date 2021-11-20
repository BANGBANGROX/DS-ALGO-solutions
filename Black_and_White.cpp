// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

ll numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends



//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
ll numOfWays(int N, int M) {
    // write code here
    ll total = (((ll)N * M) % mod * (((ll)N * M) % mod - 1 + mod) % mod) % mod;

    if (N >= 1 && M >= 2) {
        total = (total - (4 * (((ll)N - 1) * ((ll)M - 2))) % mod + mod) % mod;
    }

    if (N >= 2 && M >= 1) {
        total = (total - (4 * (((ll)N - 2) * ((ll)M - 1))) % mod + mod) % mod;
    }

    return total;
}