// { Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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

            // Create the left child for the current Node
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

void preorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


// } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
    int data;
    struct Node* left, *right;
};
*/

const char marker1 = '$';
const char marker2 = '&';
unordered_set<string> subtree;
unordered_map<string, bool> value;

string dupSubUtil(Node* root, vector<Node*>& res) {
    string s = "";

    if (root == NULL) return s + marker1;

    string lstr = dupSubUtil(root->left, res);
    if (s.compare(lstr) == 0) return s;

    string rstr = dupSubUtil(root->right, res);
    if (s.compare(rstr) == 0) return s;

    s = s + to_string(root->data) + marker2 + lstr + marker2 + rstr;

    if (subtree.find(s) != subtree.end()) {
        if (value.find(s) == value.end()) {
            res.push_back(root);
            value[s] = 1;
        }
        return s;
    }

    subtree.insert(s);

    return s;
}

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
vector<Node*> printAllDups(Node* root) {
    // Code here

    subtree.clear();

    vector<Node*> res;

    dupSubUtil(root, res);

    return res;
}

// { Driver Code Starts.
int main()
{
    int t;
    scanf_s("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        vector<Node*> res = printAllDups(root);

        for (int i = 0; i < res.size(); i++) {
            preorder(res[i]);
            cout << endl;
        }
    }
    return 0;
}


// } Driver Code Ends