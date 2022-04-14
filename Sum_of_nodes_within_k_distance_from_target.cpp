// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {
    vector<Node*> targetNode(Node* root, int target) {
        if (root == NULL) return {};

        if (root->data == target) {
            vector<Node*> res;
            res.push_back(root);
            return res;
        }

        if (root->left != NULL) {
            vector<Node*> res = targetNode(root->left, target);
            if (!res.empty()) { 
                res.push_back(root); 
                return res;
            }
        }

        if (root->right != NULL) {
            vector<Node*> res = targetNode(root->right, target);
            if (!res.empty()) {
                res.push_back(root);
                return res;
            }
        }

        return {};
    }

    void findKDistantNodes(Node* root, vector<int>& res, int k, Node* parent) {
        if (root == parent || k < 0) return;

        if (root->left != NULL) {
            findKDistantNodes(root->left, res, k - 1, parent);
        }

        if (root->right != NULL) {
            findKDistantNodes(root->right, res, k - 1, parent);
        }

        res.push_back(root->data);
    }

public:
    int sum_at_distK(Node* root, int target, int k) {
        // code here
        vector<Node*> nodes = targetNode(root, target);
        vector<int> res;
        int n = nodes.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) findKDistantNodes(nodes[i], res, k, NULL);
            else findKDistantNodes(nodes[i], res, k - i, nodes[i - 1]);
        }

        for (int x : res) {
            ans += x;
        }

        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        Solution ob;
        cout << ob.sum_at_distK(root, target, k) << endl;
    }
    return 0;
}

// } Driver Code Ends