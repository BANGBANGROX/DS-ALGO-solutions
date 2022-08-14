#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
           vector<int> ans;
           int n = s.size();
           int wordLength = words[0].size();
           int len = words.size();
           int windowLength = wordLength * len;

           if (windowLength > n) return ans;

           for (int i = 0; i <= n - windowLength; ++i) {
               unordered_map<string, int> count;
               for (string word : words) {
                   ++count[word];
               }
               int k = 0;
               for (; k < len; ++k) {
                   string temp = s.substr(i + k * wordLength, wordLength);
                   if (count.find(temp) == count.end()) break;
                   --count[temp];
                   if (count[temp] < 0) break;
               }
               if (k == len) ans.push_back(i);
           }

           return ans;
    }
};