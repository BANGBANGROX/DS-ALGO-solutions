#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
         int l = 1;
         int r = INT_MAX;
         int ans = -1;
         ll lcm = (ll) divisor1 * divisor2 / __gcd(divisor1, divisor2);

         while (l <= r) {
             int mid = (l + ((r - l) >> 1));
             int cnt1 = mid - mid / divisor1;
             int cnt2 = mid - mid / divisor2;
             ll combined = mid - mid / lcm;
             if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 &&
             combined >= uniqueCnt1 + uniqueCnt2) {
                 ans = mid;
                 r = mid - 1;
             }
             else l = mid + 1;
         }

         return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int divisor1, divisor2, uniqueCnt1, uniqueCnt2;
        cin >> divisor1 >> divisor2 >> uniqueCnt1 >> uniqueCnt2;

        Solution solution;
        cout << solution.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    }

    return 0;
}
