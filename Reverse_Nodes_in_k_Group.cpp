#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return res;
    }

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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        ListNode* newListHead = NULL, * newListTail = newListHead, * temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            newListTail = push(newListTail, temp->val);
            if (newListHead == NULL) newListHead = newListTail;
            temp = temp->next;
        }
        
        if (count != k) return head;

        head = newListHead;
        newListHead = reverseList(newListHead);
        head->next = reverseKGroup(temp, k);

        return newListHead;
    }
};