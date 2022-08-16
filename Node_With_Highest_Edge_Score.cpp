#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        long maxCount = 0;
        vector<long> count(n);

        for (int i = 0; i < n; ++i) {
            count[edges[i]] += i;
        }

        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ans = i;
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> edges(n);
        for (int &x: edges) cin >> x;

        Solution solution;
        cout << solution.edgeScore(edges) << endl;
    }

    return 0;
}