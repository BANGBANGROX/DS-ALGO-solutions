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
	bool done;
	ListNode* previousLeft;
	ListNode* left;
	ListNode* ans;
	int pos;

	void swapNodesUtil(ListNode* previousRight, ListNode* right) {
		if (right == NULL) return;

		swapNodesUtil(right, right->next);

		if (done) return;

		if (pos == 1) {
			ListNode* rightNext = right->next;
			ListNode* leftNext = left->next;
			if (left == previousRight) {
				if (previousLeft != NULL) previousLeft->next = right;
				left->next = right->next;
				right->next = left;
				if (previousLeft == NULL) ans = right;
				return;
			}
			if (right == previousLeft) {
				if (previousRight != NULL) previousRight->next = left;
				right->next = left->next;
				left->next = right;
				if (previousRight == NULL) ans = left;
				return;
			}
			right->next = leftNext;
			left->next = rightNext;
			if (previousRight != NULL) previousRight->next = left;
			if (previousLeft != NULL) previousLeft->next = right;
			if (previousLeft == NULL) ans = right;
			if (previousRight == NULL) ans = left;
			done = true;
			return;
		}

		--pos;
		previousLeft = left;
		left = left->next;
	}

public:
	ListNode* swapNodes(ListNode* head, int k) {
		previousLeft = NULL;
		left = head;
		pos = k;
		done = false;
		ans = head;

		swapNodesUtil(NULL, head);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}