// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	struct Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
	int data;
	struct node* next;

	node(int x){
		data = x;
		next = NULL;
	}

}*head;
*/
class Solution {
public:
	Node* pairWiseSwap(struct Node* head) {
		// The task is to complete this method
		if (head == NULL || head->next == NULL) return head;

		Node* currentNode = head->next;
		Node* save = currentNode->next;
		Node* previousNode = head;

		currentNode->next = previousNode;
		head->next = pairWiseSwap(save);

		return currentNode;
	}
};

// { Driver Code Starts.

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int data;
		cin >> data;
		struct Node* head = new Node(data);
		struct Node* tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node* failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node* temp = head;
		while (temp) {
			if (mp[temp] != temp->data) {
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag)
			printList(failure);
		else
			printList(head);
	}
	return 0;
}
// } Driver Code Ends