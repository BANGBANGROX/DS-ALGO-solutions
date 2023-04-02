#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ans;
        int charsInSection = 2 * (numRows - 1);
        int n = (int) s.size();

        for (int currentRow = 0; currentRow < numRows; ++currentRow) {
            int i = currentRow;
            while (i < n) {
                ans += s[i];
                if (currentRow != 0 && currentRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currentRow;
                    int secondIndex = i + charsInBetween;
                    if (secondIndex < n) {
                        ans += s[secondIndex];
                    }
                }
                i += charsInSection;
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        int numRows;
        cin >> numRows;

        Solution solution;
        cout << solution.convert(s, numRows) << endl;
    }

    return 0;
}
