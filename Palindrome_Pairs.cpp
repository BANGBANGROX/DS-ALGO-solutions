// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function Template for C++

struct TrieNode {
    TrieNode* children[26];
    vector<int> pos;
    int id;
    bool isLeaf;
};

TrieNode* getNode() {
    TrieNode* newNode = new TrieNode;

    for (int i = 0; i < 26; ++i) {
        newNode->children[i] = NULL;
    }

    newNode->isLeaf = false;
    newNode->id = -1;

    return newNode;
}

bool isPalindrome(string word, int l, int r) {
    while (l < r) {
        if (word[l] != word[r]) return false;
        ++l;
        --r;
    }

    return true;
}

void insert(TrieNode* root, string word, int id) {
    TrieNode* pCrawl = root;
    int n = word.size();

    for (int i = n - 1; i >= 0; --i) {
        int index = word[i] - 'a';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        if (isPalindrome(word, 0, i)) pCrawl->pos.push_back(id);
        pCrawl = pCrawl->children[index];
    }
    
    pCrawl->pos.push_back(id);
    pCrawl->id = id;
    pCrawl->isLeaf = true;
}

void search(TrieNode* root, string word, int id, vector<vector<int>>& result) {
    TrieNode* pCrawl = root;
    int n = word.size();

    for (int i = 0; i < n; ++i) {
        int index = word[i] - 'a';
        if (pCrawl->id >= 0 && pCrawl->id != id && isPalindrome(word, i, n - 1)) {
            result.push_back({ id,pCrawl->id });
        }
        if (!pCrawl->children[index]) return;
        pCrawl = pCrawl->children[index];
    }

    for (int i : pCrawl->pos) {
        if (i == id) continue;
        result.push_back({ id,i });
    }
}

class Solution {
public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int n, string arr[]) {
        // code here
        TrieNode* root = getNode();

        for (int i = 0; i < n; ++i) {
            insert(root, arr[i], i);
        }

        vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            search(root, arr[i], i, result);
            if (result.size() > 0) return true;
        }

        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string* arr = new string[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends