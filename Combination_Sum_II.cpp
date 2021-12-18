#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> candidates, curr;
    int n = 0;
    vector<vector<int>> ans;

    void generate(int index, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < n; ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (target - candidates[i] < 0) return;
            curr.push_back(candidates[i]);
            generate(i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        this->candidates = candidates;
        n = candidates.size();

        generate(0, target);
       
        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, target;
        cin >> n;
        vector<int> candidates(n);
        for (int& x : candidates) cin >> x;
        cin >> target;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum2(candidates, target);
        for (vector<int>x : ans) {
            for (int y : x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}