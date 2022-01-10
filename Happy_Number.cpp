#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
private: 
    int findSum(int n) {
        int ans = 0;

        while (n) {
            int rem = n % 10;
            ans += rem * rem;
            n /= 10;
        }

        return ans;
    }

public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;

        while (n != 1 && !mp[n]) {
            mp[n] = true;
            n = findSum(n);
        }

        return n == 1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Solution obj;
        if (obj.isHappy(n)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}