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
	ListNode* mergeLists(ListNode* list1, ListNode* list2) {
		ListNode* mergedHead = new ListNode();
		ListNode* mergedTail = mergedHead;

		while (list1 != NULL && list2 != NULL) {
			if (list1->val < list2->val) {
				mergedTail->next = list1;
				mergedTail = mergedTail->next;
				list1 = list1->next;
			}
			else {
				mergedTail->next = list2;
				mergedTail = mergedTail->next;
				list2 = list2->next;
			}
		}

		mergedTail->next = (list1 == NULL) ? list2 : list1;

		return mergedHead->next;
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		int last = k - 1;

		if (k == 0) return NULL;

		while (last != 0) {
			int i = 0;
			int j = last;
			while (i < j) {
				lists[i] = mergeLists(lists[i], lists[j]);
				++i;
				--j;
				if (i >= j) last = j;
			}
		}

		return lists[0];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}