#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, * fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(ListNode* head) {
    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n;
        
        cin >> x;

        ListNode* head = new ListNode(x);
        ListNode* tail = head;

        for (int i = 1; i < n; ++i) {
            cin >> x;
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        ListNode* res = middleNode(head);
        printList(res);
    }

    return 0;
}