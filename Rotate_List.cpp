#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
};

class Solution {
	int listLength(ListNode* head) {
		int len = 0;

		while (head != NULL) {
			++len;
			head = head->next;
		}

		return len;
	}

public:
	ListNode* rotateRight(ListNode* head, int k) {
		int n = listLength(head);

		if (n == 0) return NULL;

		k %= n;

		if (k == 0) return head;

		int nodePosition = n - k + 1;
		int pos = 1;
		ListNode* node = head;
		ListNode* previousNode = NULL;
		ListNode* lastNode = head;

		while (lastNode->next != NULL) {
			if (pos < nodePosition) {
				previousNode = node;
				node = node->next;
				++pos;
			}
			lastNode = lastNode->next;
		}

		lastNode->next = head;

		assert(previousNode != NULL);
		previousNode->next = NULL;

		return node;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}