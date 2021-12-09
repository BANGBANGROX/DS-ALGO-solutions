#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* push(ListNode* head, int val) {
    if (head == NULL) head = new ListNode(val);
    else {
        head->next = new ListNode(val);
        head = head->next;
    }

    return head;
}

ListNode* oddEvenList(ListNode* head) {
    ListNode* oddHead = NULL, * oddTail = NULL, * evenHead = NULL, * evenTail = NULL;
    int index = 1;

    while (head != NULL) {
        if (index) {
            oddTail = push(oddTail, head->val);
            if (oddHead == NULL) oddHead = oddTail;
        }
        else {
            evenTail = push(evenTail, head->val);
            if (evenHead == NULL) evenHead = evenTail;
        }
        head = head->next;
    }

    if (oddTail) oddTail->next = evenHead;
    else oddHead = evenHead;

    return oddHead;
}

