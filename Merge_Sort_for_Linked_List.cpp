// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution {
public:
    //Function to sort the given linked list using Merge Sort.
    Node* push(Node* head, int data) {
        if (head == NULL) {
            head = new Node(data);
        }
        else {
            head->next = new Node(data);
            head = head->next;
        }
    }

    void split(Node* source, Node** firstHalf, Node** secondHalf) {
        Node* slow = source;
        Node* fast = slow->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *firstHalf = source;
        *secondHalf = slow->next;
        slow->next = NULL;
    }

    Node* merge(Node* firstHalf, Node* secondHalf) {
        Node* newList = NULL, * newListTail = newList;
        Node* a = firstHalf, * b = secondHalf;

        while (a != NULL && b != NULL) {
            int x = a->data, y = b->data;
            if (x <= y) {
                newListTail = push(newListTail, x);
                if (newList == NULL) newList = newListTail;
                a = a->next;
            }
            else {
                newListTail = push(newListTail, y);
                if (newList == NULL) newList = newListTail;
                b = b->next;
            }
        }

        while (a != NULL) {
            int x = a->data;
            newListTail = push(newListTail, x);
            if (newList == NULL) newList = newListTail;
            a = a->next;
        }

        while (b != NULL) {
            int x = b->data;
            newListTail = push(newListTail, x);
            if (newList == NULL) newList = newListTail;
            b = b->next;
        }

        return newList;
    }

    void mergeSortUtil(Node** headRef) {
        Node *head = *headRef;
        Node* firstHalf, * secondHalf;
        firstHalf = secondHalf = NULL;

        if (head == NULL || head->next == NULL) return;

        split(head, &firstHalf, &secondHalf);

        mergeSortUtil(&firstHalf);
        mergeSortUtil(&secondHalf);

        *headRef = merge(firstHalf, secondHalf);
    }

    Node* mergeSort(Node* head) {
        mergeSortUtil(&head);

        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
