// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* start = NULL;


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    void pushNode(Node** head, int x) {
        Node* curr = *head;

        if (curr == NULL) curr = new Node(x);
        else {
            curr->next = new Node(x);
            curr = curr->next;
        }

        *head = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Add code here
        Node* zeroesHead, * zeroesTail, * onesHead, * onesTail, * twosHead, * twosTail, * tempHead = head;
        zeroesHead = zeroesTail = onesHead = onesTail = twosHead = twosTail = NULL;

        while (tempHead != NULL) {
            int x = tempHead->data;
            if (x == 0) {
                pushNode(&zeroesTail, 0);
                if (zeroesHead == NULL) zeroesHead = zeroesTail;
            }
            else if (x == 1) {
                pushNode(&onesTail, 1);
                if (onesHead == NULL) onesHead = onesTail;
            }
            else {
                pushNode(&twosTail, 2);
                if (twosHead == NULL) twosHead = twosTail;
            }
            tempHead = tempHead->next;
        }

        if (zeroesHead != NULL) {
            if (onesHead != NULL) {
                zeroesTail->next = onesHead;
                onesTail->next = twosHead;
            }
            else {
                zeroesTail->next = twosHead;
            }
            head = zeroesHead;
        }

        else if (onesHead != NULL) {
            onesTail->next = twosHead;
            head = onesHead;
        }

        else {
            head = twosHead;
        }

        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node* temp = NULL;
    for (i = 0; i < n; i++) {
        scanf_s("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        }
        else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf_s("%d", &t);

    while (t--) {
        scanf_s("%d", &n);

        insert(n);
        Solution ob;
        struct Node* newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
