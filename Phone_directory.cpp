// Initial Template for C++

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

const int MAX = 26;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        bool isLast;

        TrieNode() {
            for (int i = 0; i < MAX; ++i) {
                child[i] = NULL;
            }
            isLast = false;
        }
    };

    TrieNode* root = NULL;

    void insert(string s) {
        int n = s.size();
        TrieNode* pNode = root;

        for (int i = 0; i < n; ++i) {
            if (!pNode->child[s[i] - 'a']) {
                pNode->child[s[i] - 'a'] = new TrieNode();
            }
            pNode = pNode->child[s[i] - 'a'];
        }

        pNode->isLast = true;
    }

    void displayContactsUtil(TrieNode* root, string prefix, vector<string>& res) {
        if (root->isLast) {
            res.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (root->child[ch - 'a']) {
                displayContactsUtil(root->child[ch - 'a'], prefix + char(ch), res);
            }
        }
    }

    void insertIntoTrie(string contact[], int n) {
        root = new TrieNode();

        for (int i = 0; i < n; ++i) {
            insert(contact[i]);
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // code here

        insertIntoTrie(contact, n);

        vector<vector<string>> res;
        TrieNode* prevNode = root;
        string prefix("");
        int len = s.length();
        bool done = false;

        for (int i = 0; i < len; ++i) {
            if (done) {
                res.push_back({ "0" });
                continue;
            }
            prefix += s[i];
            char last = s[i];
            TrieNode* currNode = prevNode->child[last - 'a'];
            if (!currNode) {
                res.push_back({ "0" });
                done = true;
                continue;
            }
            vector<string> temp;
            displayContactsUtil(currNode, prefix, temp);
            res.push_back(temp);
            prevNode = currNode;
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string* contact = new string[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++) {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends