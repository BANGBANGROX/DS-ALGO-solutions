// { Driver Code Starts
#include <bits/stdc++.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* bottom;

	Node(int x) {
		data = x;
		next = NULL;
		bottom = NULL;
	}

};

using namespace std;

void printList(Node* Node)
{
	while (Node != NULL)
	{
		printf("%d ", Node->data);
		Node = Node->bottom;
	}
}

Node* flatten(Node* root);

int main(void) {

	int t;
	cin >> t;
	while (t--) {
		int n, m, flag = 1, flag1 = 1;
		struct Node* temp = NULL;
		struct Node* head = NULL;
		struct Node* pre = NULL;
		struct Node* tempB = NULL;
		struct Node* preB = NULL;
		cin >> n;
		int* work = new int[n];
		for (int i = 0; i < n; i++)
			cin >> work[i];
		for (int i = 0; i < n; i++) {
			m = work[i];
			--m;
			int data;
			scanf_s("%d", &data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;

			if (flag) {
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else {
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for (int j = 0; j < m; j++) {

				int temp_data;
				scanf_s("%d", &temp_data);
				tempB = new Node(temp_data);

				if (flag1) {
					temp->bottom = tempB;
					preB = tempB;
					flag1 = 0;
				}
				else {
					preB->bottom = tempB;
					preB = tempB;
				}
			}
		}
		Node* fun = head;
		Node* fun2 = head;

		Node* root = flatten(head);
		printList(root);
		cout << endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
		data = x;
		next = NULL;
		bottom = NULL;
	}

};
*/

/*  Function which returns the  root of
	the flattened linked list. */

void pushNode(Node** head, int data) {
	Node* curr = *head;
	if (curr == NULL) {
		curr = new Node(data);
	}
	else {
		curr->bottom = new Node(data);
		curr = curr->bottom;
	}

	*head = curr;
}

Node* mergeLists(Node* list1, Node* list2) {
	Node* resList = NULL, * resListTail = NULL;
	Node* a = list1, * b = list2;

	while (a != NULL && b != NULL) {
		int x = a->data, y = b->data;
		if (x < y) {
			if (resList == NULL) {
				pushNode(&resListTail, x);
				resList = resListTail;
			}
			else {
				pushNode(&resListTail, x);
			}
			a = a->bottom;
		}
		else {
			if (resList == NULL) {
				pushNode(&resListTail, y);
				resList = resListTail;
			}
			else {
				pushNode(&resListTail, y);
			}
			b = b->bottom;
		}
	}

	while (a != NULL) {
		int x = a->data;
		if (resList == NULL) {
			pushNode(&resListTail, x);
			resList = resListTail;
		}
		else {
			pushNode(&resListTail, x);
		}
		a = a->bottom;
	}

	while (b != NULL) {
		int y = b->data;
		if (resList == NULL) {
			pushNode(&resListTail, y);
			resList = resListTail;
		}
		else {
			pushNode(&resListTail, y);
		}
		b = b->bottom;
	}

	return resList;
}
Node* flatten(Node* root) {
	// Your code here
	if (root == NULL) return NULL;

	Node* newRoot = root;
	Node* res = newRoot;

	newRoot = newRoot->next;

	while (newRoot != NULL) {
		res = mergeLists(res, newRoot);
		newRoot = newRoot->next;
	}

	return res;
}


