#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> answer;
        unordered_set<int> current;

        current.insert(0);

        for (int x : nums) {
            unordered_set<int> current2;
            for (int y : current) {
                current2.insert(x | y);
            }
            current2.insert(x);
            current = current2;
            for (int y : current2) {
                answer.insert(y);
            }
        }

        return (int)answer.size();
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int& x : nums) {
            cin >> x;
        }

        Solution solution;
        cout << solution.subarrayBitwiseORs(nums) << endl;
    }

    return 0;
}