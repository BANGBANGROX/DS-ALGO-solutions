#include<bits/stdc++.h>
using namespace std;

class Solution {
	struct ListNode {
		int val;
		ListNode* next;

		ListNode(int val) {
			this->val = val;
			next = NULL;
		}
	};

public:
	ListNode* mergeNodes(ListNode* head) {
		ListNode* resultHead = new ListNode(0);
		ListNode* resultTail = resultHead;

		head = head->next;

		while (head != NULL) {
			int currSum = 0;
			while (head->val > 0) {
				currSum += head->val;
				head = head->next;
			}
			resultTail->next = new ListNode(currSum);
			resultTail = resultTail->next;
			head = head->next;
		}

		return resultHead->next;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}