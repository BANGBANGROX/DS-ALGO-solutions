#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        int n = word.size();

        for (int i = 0; i < n; ++i) {
            int ind = word[i] - 'a';
            if (node->children[ind] == NULL) {
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
        }

        node->isEnd = true;
    }

    TrieNode* searchWord(string word) {
        if (root == NULL) return NULL;

        TrieNode* node = root;
        int n = word.size();

        for (int i = 0; i < n; ++i) {
            int ind = word[i] - 'a';
            if (node->children[ind] == NULL) return NULL;
            node = node->children[ind];
        }

        return node;
    }

    bool search(string word) {
        TrieNode* node = searchWord(word);

        return node != NULL && node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = searchWord(prefix);

        return node != NULL;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // return True
    cout << trie.search("app") << endl;     // return False
    cout << trie.startsWith("app") << endl; // return True
    trie.insert("app");
    cout << trie.search("app") << endl;     // return True

	return 0;
}