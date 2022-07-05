// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        queue<Node*> q1;
        queue<Node*> q2;

        if (root1 == NULL || root2 == NULL) return (root1 == NULL && root2 == NULL);

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int m = q1.size();
            int n = q2.size();
            if (m != n) return false;
            unordered_map<int, int> count;
            for (int i = 0; i < m; ++i) {
                Node* node1 = q1.front();
                Node* node2 = q2.front();
                ++count[node1->data];
                --count[node2->data];
                q1.pop();
                q2.pop();
                if (node1->left != NULL) {
                    q1.push(node1->left);
                }
                if (node1->right != NULL) {
                    q1.push(node1->right);
                }
                if (node2->left != NULL) {
                    q2.push(node2->left);
                }
                if (node2->right != NULL) {
                    q2.push(node2->right);
                }
            }
            for (pair<int, int> x : count) {
                if (x.second != 0) return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf_s("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node* root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node* root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}
// } Driver Code Ends