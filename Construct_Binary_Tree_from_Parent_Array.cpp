//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int>& v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty())
    {
        Node* n = q.front();
        q.pop();

        if (n == next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left)
        {
            q.push(n->left);
            if (next_row == NULL) next_row = n->left;
        }

        if (n->right)
        {
            q.push(n->right);
            if (next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {

    Node* createTreeUtil(vector<vector<int>>& tree, int node) {
        Node* root = new Node(node);
        int size = tree[node].size();
        
        if (size == 0) return root;

        else if (size == 1) root->left = createTreeUtil(tree, tree[node][0]);

        else {
            root->left = createTreeUtil(tree, tree[node][0]);
            root->right = createTreeUtil(tree, tree[node][1]);
        }

        return root;
    }

public:
    //Function to construct binary tree from parent array.
    Node* createTree(int parent[], int n) {
        // Your code here
        vector<vector<int>> tree(n);
        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) tree[parent[i]].push_back(i);
            else root = i;
        }

        return createTreeUtil(tree, root);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        Node* res = ob.createTree(a, n);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}


// } Driver Code Ends