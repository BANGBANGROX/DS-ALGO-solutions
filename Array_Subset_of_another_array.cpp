// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int* a1 = new int[n], * a2 = new int[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, bool> isPresent;

    for (int i = 0; i < n; ++i) {
        isPresent[a1[i]] = true;
    }

    for (int i = 0; i < m; ++i) {
        if (isPresent.find(a2[i]) == isPresent.end()) return "No";
    }

    return "Yes";
}