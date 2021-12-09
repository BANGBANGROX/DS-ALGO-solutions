// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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

        // Get the current Node's value from the string
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
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
// User function Template for C++

class Solution {

public:

    const int inf = 1e9;

    struct pqStr {
        int value, index, listNum;
    };

    struct comp {
        bool operator()(pqStr& lhs, pqStr& rhs) {
            return lhs.value > rhs.value;
        }
    };

    pair<int, int> findShortestRange(vector<vector<int>>& lists) {
        int maxValue = 0, n = lists.size();
        pair<int, int> res = { 0,inf };
        priority_queue<pqStr, vector<pqStr>, comp> pq;

        for (int i = 0; i < n; ++i) {
            pq.push({ lists[i][0],0,i });
            maxValue = max(maxValue, lists[i][0]);
        }

        while (true) {
            pqStr curr = pq.top();
            pq.pop();
            int minValue = curr.value, index = curr.index, listNum = curr.listNum;
            int diff = maxValue - minValue;
            if (diff < res.second - res.first) res = { minValue,maxValue };
            if (index == lists[listNum].size() - 1) break;
            pq.push({ lists[listNum][index + 1], index + 1, listNum });
            maxValue = max(maxValue, lists[listNum][index + 1]);
        }

        return res;
    }

    pair<int, int> shortestRange(Node* root) {
        // Your code goes here
        vector<vector<int>> lists;
        queue<Node*> q;
        
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> nums;
            while (size--) {
                Node* curr = q.front();
                q.pop();
                nums.push_back(curr->data);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            lists.push_back(nums);
        }

        return findShortestRange(lists);
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    scanf_s("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } Driver Code Ends
