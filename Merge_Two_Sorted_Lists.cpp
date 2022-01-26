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

	ListNode(int x, ListNode* nextPtr) {
		val = x;
		next = nextPtr;
	}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}