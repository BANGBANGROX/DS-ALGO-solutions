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
    if (curr == NULL) {
        curr = new ListNode(val);
    }
    else {
        curr->next = new ListNode(val);
        curr = curr->next;
    }

    return curr;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resHead = NULL, * resTail = resHead;
    int carry = 0;

    while (l1 && l2) {
        int val = l1->val + l2->val + carry;
        carry = val / 10;
        val %= 10;
        resTail = push(resTail, val);
        if (resHead == NULL) resHead = resTail;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        int val = l1->val + carry;
        carry = val / 10;
        val %= 10;
        resTail = push(resTail, val);
        if (resHead == NULL) resHead = resTail;
        l1 = l1->next;
    }

    while (l2) {
        int val = l2->val + carry;
        carry = val / 10;
        val %= 10;
        resTail = push(resTail, val);
        if (resHead == NULL) resHead = resTail;
        l2 = l2->next;
    }
    
    if (carry) {
        resTail = push(resTail, carry);
        if (resHead == NULL) resHead = resTail;
    }

    return resHead;
}
