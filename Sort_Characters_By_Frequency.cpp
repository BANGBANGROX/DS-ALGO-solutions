#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
private:
     unordered_map<char, int> freq;

public:
    string frequencySort(string s) {
        int n = s.size();
        string ans("");
        priority_queue<pair<int, char>> pq;

        for (char ch : s) {
            ++freq[ch];
        }
        
        for (char ch : s) {
            if (freq[ch] != 0) {
                pq.push({ freq[ch],ch });
                freq[ch] = 0;
            }
        }

        while (!pq.empty()) {
            pair<char, int> x = pq.top();
            pq.pop();
            char ch = x.second;
            int  f = x.first;
            while (f--) ans += ch;
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

        Solution obj;
        cout << obj.frequencySort(s) << endl;
    }

    return 0;
}
