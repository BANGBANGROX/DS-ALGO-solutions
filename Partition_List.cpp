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
	ListNode* partition(ListNode* head, int x) {
		ListNode* lesserHead = new ListNode(0);
		ListNode* lesserTail = lesserHead;
		ListNode* greaterHead = new ListNode(0);
		ListNode* greaterTail = greaterHead;

		while (head != NULL) {
			if (head->val < x) {
				lesserTail->next = new ListNode(head->val);
				lesserTail = lesserTail->next;
			}
			else {
				greaterTail->next = new ListNode(head->val);
				greaterTail = greaterTail->next;
			}
			head = head->next;
		}

		lesserTail->next = greaterHead->next;

		if (lesserHead->next == NULL) return greaterHead->next;

		return lesserHead->next;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}