//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;

        TrieNode() {
            children = vector<TrieNode*>(26);
            isEnd = false;

            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    void add(string& s) {
        TrieNode* pCrawl = root;

        for (char ch : s) {
            int idx = ch - 'a';
            if (pCrawl->children[idx] == nullptr) {
                pCrawl->children[idx] = new TrieNode();
            }
            pCrawl = pCrawl->children[idx];
        }

        pCrawl->isEnd = true;
    }

    bool search(TrieNode* pCrawl, string& s, int index) {
        if (pCrawl == nullptr) return false;

        if (index == (int)s.size()) return pCrawl->isEnd;

        for (int i = index; i < (int)s.size(); ++i) {
            if (pCrawl == nullptr) return false;
            int idx = s[i] - 'a';
            if (pCrawl->isEnd) {
                if (pCrawl->children[idx] != nullptr) {
                    return search(pCrawl->children[idx], s, i + 1) ||
                        search(root->children[idx], s, i + 1);
                }
                return search(root->children[idx], s, i + 1);
            }
            pCrawl = pCrawl->children[idx];
        }

        return pCrawl != nullptr && pCrawl->isEnd;
    }

public:
    // A : given string to search
    // B : vector of available strings

    int wordBreak(string s, vector<string>& dictionary) {
        //code here
        root = new TrieNode();

        for (string word : dictionary) {
            add(word);
        }

        return search(root, s, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends