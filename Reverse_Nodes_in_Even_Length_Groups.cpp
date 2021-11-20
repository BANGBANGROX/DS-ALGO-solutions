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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int size = 1;
        ListNode* tempHead = head;
        ListNode* newHead = NULL, * newTail = NULL;

        while (tempHead != NULL) {
            int count = 0;
            vector<int> group;
            while (count < size && tempHead != NULL) {
                group.push_back(tempHead->val);
                ++count;
                tempHead = tempHead->next;
            }
            if (count == 0) break;
            if (count % 2 == 0) reverse(group.begin(), group.end());
            for (int val : group) {
                if (newTail == NULL) {
                    newTail = new ListNode(val);
                    if (newHead == NULL) newHead = newTail;
                }
                else {
                    newTail->next = new ListNode(val);
                    newTail = newTail->next;
                }
            }
        }

        return newHead;
    }
};
