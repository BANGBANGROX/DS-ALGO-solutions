#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;

    void dfs(unordered_map<string, unordered_set<string>>& graph, string& beginWord,
             string& endWord, vector<string>& currentPath) {
        currentPath.push_back(beginWord);

        if (beginWord.compare(endWord) == 0) {
            ans.push_back(currentPath);
            currentPath.pop_back();
            return;
        }

        for (string child : graph[beginWord]) {
            dfs(graph, child, endWord, currentPath);
        }

        currentPath.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
           unordered_map<string, unordered_set<string>> graph;
           unordered_map<string, int> level;
           unordered_set<string> dictionary(wordList.begin(), wordList.end());
           queue<string> q;
           vector<string> currentPath;

           q.push(beginWord);
           level[beginWord] = 0;

           while (!q.empty()) {
               string word = q.front();
               string tempWord = word;
               q.pop();
               int n = word.size();
               for (char ch = 'a'; ch <= 'z'; ++ch) {
                   for (int i = 0; i < n; ++i) {
                       if (word[i] == ch) continue;
                       char temp = word[i];
                       word[i] = ch;
                       if (dictionary.count(word) > 0) {
                           if (level.count(word) == 0) {
                               level[word] = level[tempWord] + 1;
                               q.push(word);
                               graph[tempWord].insert(word);
                           }
                           else if (level[word] == 1 + level[tempWord]) {
                               graph[tempWord].insert(word);
                           }
                       }
                       word[i] = temp;
                   }
               }
           }

           dfs(graph, beginWord, endWord, currentPath);

           return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string beginWord;
        cin >> beginWord;
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (string &x: wordList) cin >> x;
        string endWord;
        cin >> endWord;

        Solution solution;
        vector<vector<string>> ans = solution.findLadders(beginWord, endWord, wordList);
        for (vector<string> &x: ans) {
            for (string &y: x) cout << y << " ";
            cout << endl;
        }
    }
}