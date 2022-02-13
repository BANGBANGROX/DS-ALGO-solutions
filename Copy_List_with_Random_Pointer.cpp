#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        Node* temp = head;
        Node* newHead = new Node(0);
        Node* newTail = newHead;

        while (temp != NULL) {
            newTail->next = new Node(temp->val);
            newTail = newTail->next;
            mapping[temp] = newTail;
            temp = temp->next;
        }

        temp = head;
        newTail = newHead->next;

        while (temp != NULL) {
            if (temp->random == NULL) {
                temp = temp->next;
                newTail = newTail->next;
                continue;
            }
            newTail->random = mapping[temp->random];
            temp = temp->next;
            newTail = newTail->next;
        }

        return newHead->next;
    }
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}