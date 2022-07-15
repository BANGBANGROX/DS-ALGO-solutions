// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A BST node
struct Node
{
	int data;
	struct Node* left, * right;
};

// A utility function to create a new Binary Tree Node
struct Node* newNode(int item)
{
	struct Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
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
//User function Template for C++

/*struct Node
{
	int data;
	struct Node *left, *right;
};*/

class Solution {
	int index;

	void inorderTraversal(Node* root, vector<int>& inorder) {
		if (root == NULL) return;

		inorderTraversal(root->left, inorder);

		inorder.push_back(root->data);

		inorderTraversal(root->right, inorder);
	}

	void overwrite(Node* root, vector<int>& ans) {
		if (root == NULL) return;

		overwrite(root->left, ans);

		root->data = ans[index];
		++index;

		overwrite(root->right, ans);
	}

public:
	void transformTree(Node* root) {
		//code here
		vector<int> inorder;

		inorderTraversal(root, inorder);

		int n = inorder.size();
		vector<int> ans(n);

		ans[n - 1] = 0;

		for (int i = n - 2; i >= 0; --i) {
			ans[i] = inorder[i + 1] + ans[i + 1];
		}

		index = 0;

		overwrite(root, ans);
	}
};

// { Driver Code Starts.

void printInorder(struct Node* root)
{
	if (root == NULL) return;

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

// Driver Program to test above functions
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{

		string inp, ch;
		getline(cin, inp);

		struct Node* root = buildTree(inp);

		Solution ob;
		ob.transformTree(root);
		printInorder(root);

		cout << "\n";
	}


	return 0;
}

// } Driver Code Ends