#include<bits/stdc++.h>
using namespace std;

class StreamChecker {
public:
    class TrieNode {
    public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }

        void insert(string word) {
            reverse(begin(word), end(word));

            TrieNode* node = this;

            for (char c : word) {
                int idx = c - 'a';
                if (node->children[idx] == NULL) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }

            node->isEnd = true;
        }
    };

    TrieNode trie;
    vector<char> queries;
    int maxLen = 0;

    StreamChecker(vector<string>& words) {
        for (string word : words) {
            trie.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
    }

    bool query(char letter) {
        queries.push_back(letter);

        if (maxLen < queries.size()) queries.erase(queries.begin());

        TrieNode* curr = &trie;

        for (int i = queries.size() - 1; i > -1; --i) {
            int idx = queries[i] - 'a';
            if (curr->isEnd) return true;
            if (curr->children[idx] == NULL) return false;
            curr = curr->children[idx];
        }

        return curr->isEnd;
    }
};

int main() {
    vector<string> words({ "cd","f","kl" });
    StreamChecker streamChecker(words);

    cout << streamChecker.query('a') << endl; // return False
    cout << streamChecker.query('b') << endl; // return False
    cout << streamChecker.query('c') << endl; // return False
    cout << streamChecker.query('d') << endl; // return True, because 'cd' is in the wordlist
    cout << streamChecker.query('e') << endl; // return False
    cout << streamChecker.query('f') << endl; // return True, because 'f' is in the wordlist
    cout << streamChecker.query('g') << endl; // return False
    cout << streamChecker.query('h') << endl; // return False
    cout << streamChecker.query('i') << endl; // return False
    cout << streamChecker.query('j') << endl; // return False
    cout << streamChecker.query('k') << endl; // return False
    cout << streamChecker.query('l') << endl; // return True, because 'kl' is in the wordlist

    return 0;
}