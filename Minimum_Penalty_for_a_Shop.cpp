#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = (int)customers.size();
        vector<int> cnt(2);
        vector<vector<int>> prefix(n, vector<int>(2));
        vector<vector<int>> suffix(n, vector<int>(2));

        for (int i = 0; i < n; ++i) {
            if (customers[i] == 'N') {
                ++cnt[0];
            }
            else {
                ++cnt[1];
            }
            prefix[i][0] = cnt[0];
            prefix[i][1] = cnt[1];
        }

        cnt = vector<int>(2);

        for (int i = n - 1; i >= 0; --i) {
            if (customers[i] == 'N') {
                ++cnt[0];
            }
            else {
                ++cnt[1];
            }
            suffix[i][0] = cnt[0];
            suffix[i][1] = cnt[1];
        }

        int answer = 0;
        int answerLoss = suffix[0][1];

        for (int i = 1; i < n; ++i) {
            int loss = suffix[i][1] + prefix[i - 1][0];
            if (loss < answerLoss) {
                answerLoss = loss;
                answer = i;
            }
        }

        if (prefix[n - 1][0] < answerLoss) {
            answerLoss = prefix[n - 1][0];
            answer = n;
        }

        return answer;
    }
};


int main() {
    int T;
    cin >> T;

    while (T--) {
        string customers;
        cin >> customers;

        Solution solution;
        cout << solution.bestClosingTime(customers) << endl;
    }

    return 0;
}