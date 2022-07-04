// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// you are required to complete this function
// function should return the size of the 
// Largest Independent set in the tree


//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

unordered_map<Node*, int> dp;

void dfs(Node* root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) dp[root] = 1;

    dfs(root->left);
    dfs(root->right);

    int left1 = 0;
    int right1 = 0;
    int left2 = 0;
    int right2 = 0;

    if (root->left != NULL) {
        if (root->left->left != NULL) left1 = dp[root->left->left];
        if (root->left->right != NULL) left2 = dp[root->left->right];
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) right1 = dp[root->right->left];
        if (root->right->right != NULL) right2 = dp[root->right->right];
    }

    dp[root] = max(left1 + left2 + right1 + right2 + 1, dp[root->left] + dp[root->right]);
}

int LISS(Node* root) {
    //Code here
    dp.clear();

    dfs(root);

    return dp[root];
}


// { Driver Code Starts.
int main()
{
    int t;
    scanf_s("%d\n", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        cout << LISS(root) << endl;
    }
    return 0;
}
// } Driver Code Ends