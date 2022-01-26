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
	bool ans;
	int length;
	ListNode* left;

	void computeLength(ListNode* head) {
		while (head != NULL) {
			++length;
			head = head->next;
		}
	}

	void isPalindromeUtil(ListNode* head, int len) {
		if (head == NULL) return;

		isPalindromeUtil(head->next, len + 1);

		if (len >= length / 2) {
			if (left->val != head->val) {
				ans = false;
				return;
			}
			left = left->next;
		}
	}

public:
	bool isPalindrome(ListNode* head) {
		length = 0;
		left = head;
		ans = true;

		computeLength(head);

		isPalindromeUtil(head, 0);

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