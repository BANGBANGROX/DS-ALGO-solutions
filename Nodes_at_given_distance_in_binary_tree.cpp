//{ Driver Code Starts
#include<bits/stdc++.h>
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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {
    unordered_map<Node *, Node *> nodeToParent;
    Node *targetNode;

    void dfs(Node *node, Node *parent, int target) {
        if (node == NULL) return;

        nodeToParent[node] = parent;

        if (node->data == target) targetNode = node;

        dfs(node->left, node, target);
        dfs(node->right, node, target);
    }

public:
    vector<int> KDistanceNodes(Node *root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        nodeToParent.clear();
        vector<int> ans;
        queue<Node *> q;
        int distance = 0;
        unordered_set<Node *> visited;

        dfs(root, NULL, target);

        q.push(targetNode);
        visited.insert(targetNode);
        visited.insert(NULL);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* node = q.front();
                q.pop();
                assert(node != NULL);
                Node* parent = nodeToParent[node];
                Node* left = node->left;
                Node* right = node->right;
                if (distance == k) ans.push_back(node->data);
                if (visited.find(parent) == visited.end()) {
                    q.push(parent);
                    visited.insert(parent);
                }
                if (visited.find(left) == visited.end()) {
                    q.push(left);
                    visited.insert(left);
                }
                if (visited.find(right) == visited.end()) {
                    q.push(right);
                    visited.insert(right);
                }
            }
            if (!ans.empty()) break;
            ++distance;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();

    Solution x = Solution();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int target, k;
        cin>> target >> k;
        getchar();

        vector <int> res = x.KDistanceNodes(head, target, k);

        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends