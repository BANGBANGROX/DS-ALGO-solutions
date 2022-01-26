#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode() {
		val = 0;
		next = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

class Solution {
	ListNode* getMidNode(ListNode* head) {
		ListNode* midHead = NULL;

		while (head != NULL && head->next != NULL) {
			midHead = (midHead == NULL) ? head : midHead->next;
			head = head->next->next;
		}

		ListNode* mid = midHead->next;
		midHead->next = NULL;

		return mid;
	}

	ListNode* mergeList(ListNode* list1, ListNode* list2) {
		ListNode* mergedHead = new ListNode();
		ListNode* mergedTail = mergedHead;

		while (list1 != NULL && list2 != NULL) {
			if (list1->val < list2->val) {
				mergedTail->next = list1;
				list1 = list1->next;
				mergedTail = mergedTail->next;
			}
			else {
				mergedTail->next = list2;
				list2 = list2->next;
				mergedTail = mergedTail->next;
			}
		}

		mergedTail->next = (list1 == NULL) ? list2 : list1;

		return mergedHead->next;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* mid = getMidNode(head);
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);

		return mergeList(left, right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}