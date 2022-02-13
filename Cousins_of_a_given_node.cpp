// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// A Binary Tree Node
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

Node* pointer(Node* root, int n)
{
	if (root == NULL)
		return NULL;

	if (root->data == n)
		return root;

	Node* l = pointer(root->left, n);
	if (l != NULL && l->data == n)
		return l;

	Node* r = pointer(root->right, n);
	return r;

}


// } Driver Code Ends
//User function Template for C++

/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
public:
	vector<int> printCousins(Node* root, Node* node_to_find) {
		//code here
		vector<int> ans;
		queue<Node*> q;
		unordered_map<Node*, Node*> sibbling;

		if (root == NULL) return ans;

		q.push(root);

		while (!q.empty()) {
			bool nodeFound = false;
			int n = q.size();
			vector<int> currentLevel;
			for (int i = 0; i < n; ++i) {
				Node* currNode = q.front();
				q.pop();
				Node* leftChild = NULL;
				Node* rightChild = NULL;
				if (currNode->left != NULL) {
					q.push(currNode->left);
					leftChild = currNode->left;
				}
				if (currNode->right != NULL) {
					q.push(currNode->right);
					rightChild = currNode->right;
				}
				if (leftChild && rightChild) {
					sibbling[leftChild] = rightChild;
					sibbling[rightChild] = leftChild;
				}
				if (currNode == node_to_find) nodeFound = true;
				currentLevel.push_back(currNode->data);
			}
			if (nodeFound) {
				for (int val : currentLevel) {
					if (node_to_find->data == val) continue;
					if (sibbling.find(node_to_find) != sibbling.end() && sibbling[node_to_find]->data == val) continue;
					ans.push_back(val);
				}
				break;
			}
		}

		if (ans.empty()) ans.push_back(-1);

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
		int n;
		cin >> n;
		getchar();

		string inp;
		getline(cin, inp);

		struct Node* root = buildTree(inp);

		Node* p = pointer(root, n);

		Solution ob;
		vector<int> ans = ob.printCousins(root, p);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";


	}

	return 0;
}

// } Driver Code Ends