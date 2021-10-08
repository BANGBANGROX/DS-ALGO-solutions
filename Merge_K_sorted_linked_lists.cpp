// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}

};
*/

class Solution {
public:

	void addNode(Node** head, int x) {
		Node* curr = *head;

		if (curr == NULL) curr = new Node(x);
		else {
			curr->next = new Node(x);
			curr = curr->next;
		}

		*head = curr;
	}

	Node* mergeLists(Node* list1, Node* list2) {
		Node* a = list1, * b = list2, * resList = NULL, * resListTail = NULL;

		while (a != NULL && b != NULL) {
			int x = a->data, y = b->data;
			if (x < y) {
				addNode(&resListTail, x);
				if (resList == NULL) resList = resListTail;
				a = a->next;
			}
			else {
				addNode(&resListTail, y);
				if (resList == NULL) resList = resListTail;
				b = b->next;
			}
		}

		while (a != NULL) {
			int x = a->data;
			addNode(&resListTail, x);
			if (resList == NULL) resList = resListTail;
			a = a->next;
		}

		while (b != NULL) {
			int x = b->data;
			addNode(&resListTail, x);
			if (resList == NULL) resList = resListTail;
			b = b->next;
		}

		return resList;
	}

	//Function to merge K sorted linked list.
	Node* mergeKLists(Node* arr[], int k) {
		// Your code here
		int last = k - 1;

		while (last != 0) {
			int i = 0, j = last;
			while (i < j) {
				arr[i] = mergeLists(arr[i], arr[j]);
				++i;
				--j;
				if (i >= j) last = j;
			}
		}

		return arr[0];
	}
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		struct Node* arr[N];
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;

			int x;
			cin >> x;
			arr[j] = new Node(x);
			Node* curr = arr[j];
			n--;

			for (int i = 0; i < n; i++)
			{
				cin >> x;
				Node* temp = new Node(x);
				curr->next = temp;
				curr = temp;
			}
		}
		Solution obj;
		Node* res = obj.mergeKLists(arr, N);
		printList(res);

	}

	return 0;
}
// } Driver Code Ends
