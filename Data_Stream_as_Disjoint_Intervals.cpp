#include<bits/stdc++.h>

using namespace std;

class SummaryRanges {
    set<int> st;

public:
    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {
         if (st.empty()) return {};

         vector<vector<int>> ans;
         int left = -1;
         int right = -1;

         for (int x : st) {
             if (left == -1) {
                 left = right = x;
             }
             else if (x == right + 1) {
                 right = x;
             }
             else {
                 ans.push_back({left, right});
                 left = right = x;
             }
         }

         ans.push_back({left, right});

         return ans;
    }
};

void print(const vector<vector<int>>& result) {
    for (const vector<int>& x: result) {
        for (int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);      // arr = [1]
    print(summaryRanges.getIntervals()); // return [[1, 1]]
    summaryRanges.addNum(3);      // arr = [1, 3]
    print(summaryRanges.getIntervals()); // return [[1, 1], [3, 3]]
    summaryRanges.addNum(7);      // arr = [1, 3, 7]
    print(summaryRanges.getIntervals()); // return [[1, 1], [3, 3], [7, 7]]
    summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
    print(summaryRanges.getIntervals()); // return [[1, 3], [7, 7]]
    summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
    print(summaryRanges.getIntervals()); // return [[1, 3], [6, 7]]

    return 0;
}
