// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



float findMedian(struct Node* node);

// Function to Build Tree
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

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    //cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // getline(cin, s);

        cout << findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

int countNodes(Node* root) {
    int count = 0;
    Node* current = root;

    while (current != NULL) {
        if (current->left == NULL) {
            ++count;
            current = current->right;
            continue;
        }
        Node* pre = current->left;
        while (pre->right != NULL && pre->right != current) {
            pre = pre->right;
        }
        if (pre->right == NULL) {
            pre->right = current;
            current = current->left;
        }
        else {
            ++count;
            pre->right = NULL;
            current = current->right;
        }
    }

    return count;
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node* root) {
    //Code here
    int totalNodes = countNodes(root);
    int currCount = 0;
    Node* current = root, * prev = NULL, * pre = NULL;

    while (current != NULL) {
        if (current->left == NULL) {
            ++currCount;
            if (totalNodes % 2 == 1 && currCount == (totalNodes + 1) / 2) 
                return current->data;
            if (totalNodes % 2 == 0 && currCount == (totalNodes / 2 + 1) && prev != NULL)
                return (float)(prev->data + current->data) / 2;
            prev = current;
            current = current->right;
            continue;
        }
        pre = current->left;
        while (pre->right != NULL && pre->right != current) {
            pre = pre->right;
        }
        if (pre->right == NULL) {
            pre->right = current;
            current = current->left;
        }
        else {
            pre->right = NULL;
            prev = pre;
            ++currCount;
            if (totalNodes % 2 == 1 && currCount == (totalNodes + 1) / 2)
                return current->data;
            if (totalNodes % 2 == 0 && currCount == (totalNodes / 2 + 1))
                return (float)(prev->data + current->data) / 2;
            prev = current;
            current = current->right;
        }
    }

    return 0;
}


