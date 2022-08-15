//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
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
//User function template for C++
/*
Structure of the node of the tree is as follows
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution {
    int dfs(Node* root, int level, char direction, int first, int second) {
        if (root == NULL) return 0;

        if (root->data == first || root->data == second) return level;

        int left = dfs(root->left, (direction == 'r') ? level + 1 : level,
                       'l', first, second);
        int right = dfs(root->right, (direction == 'l') ? level + 1 : level,
                        'r', first, second);

        return max(left, right);
    }

    Node* findLCA(Node* root, int first, int second) {
        if (root == NULL || root->data == first || root->data == second) return root;

        Node* left = findLCA(root->left, first, second);
        Node* right = findLCA(root->right, first, second);

        if (left == NULL) return right;
        if (right == NULL) return left;

        return root;
    }

public:
    // function should return the number of turns required to go from first node to second node
    int NumberOFTurns(Node* root, int first, int second) {
        // Your code goes here
        Node* lca = findLCA(root, first, second);

        int left = dfs(lca->left, 0, 'l', first, second);
        int right = dfs(lca->right, 0, 'r', first, second);

        if (!(lca->data == first || lca->data == second)) ++left;

        return left + right == 0 ? -1 : left + right;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends