#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;

        deque<int> dq;

        for (int i = 1; i <= n; ++i) {
            dq.push_back(i);
        }

        while (dq.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            dq.pop_front();
        }

        return dq.front();
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        Solution obj;
        cout << obj.findTheWinner(n, k) << endl;
    }

    return 0;
}