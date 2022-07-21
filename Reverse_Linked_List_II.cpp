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
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == right) return head;

		int count = 1;
		ListNode* current = head;
		ListNode* previous = NULL;

		while (count < left && current != NULL) {
			previous = current;
			current = current->next;
			++count;
		}

		assert(current != NULL);
		ListNode* newCurrentNode = current->next;
		ListNode* newPreviousNode = current;
		++count;

		while (count <= right && newCurrentNode != NULL) {
			ListNode* next = newCurrentNode->next;
			newCurrentNode->next = newPreviousNode;
			newPreviousNode = newCurrentNode;
			newCurrentNode = next;
			++count;
		}

		if (previous != NULL) {
			assert(current != NULL);
			current->next = newCurrentNode;
			previous->next = newPreviousNode;
			return head;
		}

		assert(head != NULL);
		head->next = newCurrentNode;

		return newPreviousNode;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}