#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left, * right, * next;
	Node(int x) {
		val = x;
		left = right = next = NULL;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;

		queue<Node*> q;

		q.push(root);

		while (!q.empty()) {
			Node* prevNode = NULL;
			int size = q.size();
			while (size--) {
				Node* curr = q.front();
				q.pop();
				if (prevNode == NULL) prevNode = curr;
				else {
					prevNode->next = curr;
					prevNode = curr;
				}
				if (curr->left != NULL) q.push(curr->left);
				if (curr->right != NULL) q.push(curr->right);
			}
		}

		return root;
	}
};