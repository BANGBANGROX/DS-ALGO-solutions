// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    struct TrieNode {
        TrieNode* children[26];
        int frequency;
        int index;

        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }

            frequency = 1;
            index = -1;
        }
    };

    TrieNode* root;
    vector<string> ans;

    void insert(string word, int ind) {
        TrieNode* pCrawl = root;

        for (char ch : word) {
            int i = ch - 'a';
            if (pCrawl->children[i] == NULL) {
                pCrawl->children[i] = new TrieNode();
            }
            else {
                ++pCrawl->children[i]->frequency;
            }
            pCrawl->children[i]->index = ind;
            pCrawl = pCrawl->children[i];
        }
    }

    void findPrefixesUtil(TrieNode* rootNode,string current) {
        if (rootNode == NULL) return;

        if (rootNode->frequency == 1) {
            ans[rootNode->index] = current;
            return;
        }

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (rootNode->children[ch - 'a'] != NULL) {
                findPrefixesUtil(rootNode->children[ch - 'a'], current + ch);
            }
        }
    }
     
public:
    vector<string> findPrefixes(string arr[], int n) {
        //code here
        string current("");

        root = new TrieNode();
        ans = vector<string>(n);

        root->frequency = 0;

        for (int i = 0; i < n; ++i) {
            insert(arr[i], i);
        }

        findPrefixesUtil(root, current);

        return ans;
    }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string* arr = new string[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";


        cout << "\n";

    }

    return 0;
}
// } Driver Code Ends