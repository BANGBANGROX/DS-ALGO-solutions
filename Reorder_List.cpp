#include<bits/stdc++.h>
#include<unordered_map>
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
    ListNode* left = NULL;
    int size = 0;

    void findSize(ListNode* head) {
        while (head) {
            ++size;
            head = head->next;
        }
    }

    void findRight(ListNode* right, int f) {
        if (right == NULL) return;

        findRight(right->next, f + 1);

        if (f > size / 2) {
            ListNode* temp = left->next;
            left->next = right;
            right->next = temp;
            left = temp;
        }
        else if (f == size / 2) {
            right->next = NULL;
        }
    }
    

    void reorderList(ListNode* head) {
        left = head;
        
        findSize(head);
        findRight(left, 0);
    }
};

