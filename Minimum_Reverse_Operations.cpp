#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        int moves = 0;
        vector<bool> skip(n);
        vector<int> result(n, -1);
        set<int> odd;
        set<int> even;
        queue<int> q;

        for (int &ban: banned) {
            skip[ban] = true;
        }

        for (int i = 0; i < n; ++i) {
            if (i == p || skip[i]) continue;
            if ((i & 1) == 0) even.insert(i);
            else odd.insert(i);
        }

        q.push(p);

        while (!q.empty()) {
            int size = (int) q.size();
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();
                result[current] = moves;
                int minIndex = k - current - 1;
                int firstMaxIndex = n - current - 1;
                int maxIndex = k - firstMaxIndex - 1;
                if (minIndex < 0) {
                    minIndex = current - k + 1;
                }
                if (maxIndex < 0) {
                    maxIndex = firstMaxIndex - k + 1;
                }
                maxIndex = n - maxIndex - 1;
                set<int> *currentSetPtr = (minIndex & 1) == 0 ? &even : &odd;
                auto key = currentSetPtr->lower_bound(minIndex);
                while (key != currentSetPtr->end() && *key <= maxIndex) {
                    q.push(*key);
                    currentSetPtr->erase(key++);
                }
            }
            ++moves;
        }

        return result;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, p, m;
        cin >> n >> p >> m;
        vector<int> banned(m);
        for (int &x: banned) cin >> x;
        int k;
        cin >> k;

        Solution solution;
        vector<int> ans = solution.minReverseOperations(n, p, banned, k);
        for (int &x: ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
