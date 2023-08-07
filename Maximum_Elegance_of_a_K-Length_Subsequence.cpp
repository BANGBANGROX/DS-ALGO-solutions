#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
    typedef long long ll;

public:
    ll findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), greater<>());

        int n = (int)items.size();
        vector<int> duplicateProfits;
        unordered_set<int> visitedCategories;

        for (int i = 0; i < k; ++i) {
            if (!visitedCategories.insert(items[i][1]).second) {
                duplicateProfits.push_back(items[i][0]);
            }
        }

        ll profitSum = accumulate(items.begin(), items.begin() + k, 0LL,
            [](const ll s, const vector<int>& item) {
                return s + item[0];
            });
        ll answer = profitSum + (ll)((ll)visitedCategories.size() * 
            visitedCategories.size());

        for (int i = k, j = (int)duplicateProfits.size() - 1; i < n && j >= 0; ++i) {
            if (visitedCategories.insert(items[i][1]).second) {
                profitSum = profitSum - duplicateProfits[j] + items[i][0];
                answer = max(answer, profitSum +
                    (ll)((ll)visitedCategories.size() * visitedCategories.size()));
                --j;
            }
        }

        return answer;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> items(n, vector<int>(2));
        for (vector<int>& item : items) {
            cin >> item[0] >> item[1];
        }
        int k;
        cin >> k;

        Solution solution;
        cout << solution.findMaximumElegance(items, k) << endl;
    }

    return 0;
}