#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* next = head->next;
        head->next->next = head;
        head->next = NULL;
        head = next;

        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* next = head->next->next;
        ListNode* res = swapPairs(next);
        head = reverse(head);
        head->next->next = res;

        return head;
    }
};
