// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
#include<unordered_map>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
public:
    unordered_map<Node*, int> dp;

    int sumOfGrandChildren(Node* root) {
        if (root == NULL) return 0;

        int sum = 0;

        if (root->left) {
            sum += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        }
        if (root->right) {
            sum += getMaxSum(root->right->left) + getMaxSum(root->right->right);
        }

        return sum;
    }

    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node* root) {
        // Add your code here
        if (root == NULL) return 0;

        if (root->left == NULL && root->right == NULL) return root->data;

        if (dp.find(root) != dp.end()) return dp[root];

        int incl = root->data + sumOfGrandChildren(root);
        int excl = getMaxSum(root->left) + getMaxSum(root->right);

        dp[root] = max(incl, excl);

        return dp[root];
    }
};

// { Driver Code Starts.

// Driver code 
int main()
{
    int t;
    scanf_s("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.getMaxSum(root) << endl;
    }
    return 0;
}  // } Driver Code Ends