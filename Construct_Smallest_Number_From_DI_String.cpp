#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(string &result, string &pattern, int index, int previousDig,
               vector<bool> &visited) {
        if (index == (int) pattern.size()) return true;

        if ((pattern[index] == 'D' && previousDig == 1) || (pattern[index] == 'I'
                                                            && previousDig == 9))
            return false;

        if (pattern[index] == 'D') {
            for (int dig = 1; dig < previousDig; ++dig) {
                if (visited[dig]) continue;
                result += to_string(dig);
                visited[dig] = true;
                if (check(result, pattern, index + 1, dig, visited))
                    return true;
                result.pop_back();
                visited[dig] = false;
            }
        }

        if (pattern[index] == 'I') {
            for (int dig = previousDig + 1; dig < 10; ++dig) {
                if (visited[dig]) continue;
                result += to_string(dig);
                visited[dig] = true;
                if (check(result, pattern, index + 1, dig, visited))
                    return true;
                result.pop_back();
                visited[dig] = false;
            }
        }

        return false;
    }

public:
    string smallestNumber(string pattern) {
        string ans("");
        vector<bool> visited(10);

        for (int dig = 1; dig <= 9; ++dig) {
            ans += to_string(dig);
            visited[dig] = true;
            if (check(ans, pattern, 0, dig, visited)) return ans;
            ans.pop_back();
            visited[dig] = false;
        }

        return ans;
    }
};