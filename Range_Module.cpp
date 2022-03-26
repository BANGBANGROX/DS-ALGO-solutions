// https://leetcode.com/problems/range-module/

#include<bits/stdc++.h>
using namespace std;

class RangeModule {
    map<int, int> mapIntervals;

    bool getOverlappedRange(int left, int right, map<int, int>::iterator& itLeft, 
        map<int, int>::iterator& itRight) {
        itLeft = mapIntervals.upper_bound(left);
        itRight = mapIntervals.upper_bound(right);

        if (itLeft != mapIntervals.begin()) {
            --itLeft;
            if (itLeft->second < left) ++itLeft;
        }

        return itLeft != itRight;
    }

public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        map<int, int>::iterator itLeft = mapIntervals.end();
        map<int, int>::iterator itRight = mapIntervals.end();

        if (getOverlappedRange(left, right, itLeft, itRight)) {
            auto itLast = prev(itRight);
            left = min(left, itLeft->first);
            right = max(right, itLast->second);
            mapIntervals.erase(itLeft, itRight);
        }

        mapIntervals[left] = right;
    }

    bool queryRange(int left, int right) {
        map<int, int>::iterator itLeft = mapIntervals.end();
        map<int, int>::iterator itRight = mapIntervals.end();

        if (!getOverlappedRange(left, right, itLeft, itRight)) return false;

        return itLeft->first <= left && itLeft->second >= right;
    }

    void removeRange(int left, int right) {
        map<int, int>::iterator itLeft = mapIntervals.end();
        map<int, int>::iterator itRight = mapIntervals.end();

        if (!getOverlappedRange(left, right, itLeft, itRight)) return;

        auto itLast = prev(itRight);

        int start = min(left, itLeft->first);
        int end = max(right, itLast->second);

        mapIntervals.erase(itLeft, itRight);

        if (start < left) mapIntervals[start] = left;
        if (end > right) mapIntervals[right] = end;
    }
};

int main() {
    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    cout << rangeModule.queryRange(10, 14) << endl; // return True,(Every number in [10, 14) is being tracked)
    cout << rangeModule.queryRange(13, 15) << endl; // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
    cout << rangeModule.queryRange(16, 17) << endl; // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)

    return 0;
}