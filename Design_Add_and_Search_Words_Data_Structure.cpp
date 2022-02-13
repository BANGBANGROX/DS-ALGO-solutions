#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class WordDictionary {
    unordered_map<int, vector<string>> dictionary;

    bool compareWords(string word1, string word2) {
        int n = word1.size();

        for (int i = 0; i < n; ++i) {
            if (word2[i] == '.') continue;
            if (word1[i] != word2[i]) return false;
        }

        return true;
    }

public:
    WordDictionary() { }

    void addWord(string word) {
        dictionary[word.size()].push_back(word);
    }

    bool search(string word) {
        for (const string& x : dictionary[word.size()]) {
            if (compareWords(x, word)) return true;
        }

        return false;
    }
};

int main() {
    WordDictionary wordDictionary = WordDictionary();

    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << endl; // return False
    cout << wordDictionary.search("bad") << endl; // return True
    cout << wordDictionary.search(".ad") << endl; // return True
    cout << wordDictionary.search("b..") << endl; // return True

	return 0;
}