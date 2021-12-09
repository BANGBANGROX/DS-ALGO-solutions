#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* push(ListNode* curr, int val) {
	if (curr == NULL) curr = new ListNode(val);
	else {
		curr->next = new ListNode(val);
		curr = curr->next;
	}

	return curr;
}

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* temp = head, * newListHead = NULL, * newListTail = newListHead;

	while (temp != NULL) {
		int count = 0;
		ListNode* curr = temp;
		while (curr != NULL && curr->val == temp->val) {
			++count;
			curr = curr->next;
		}
		if (count < 2) {
			newListTail = push(newListTail, temp->val);
			if (newListHead == NULL) newListHead = newListTail;
		}
		temp = curr;
	}

	return newListHead;
}
