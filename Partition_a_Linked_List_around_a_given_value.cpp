// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            }
            else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node* lesserHead = new Node(0);
    Node* lesserTail = lesserHead;
    Node* greaterHead = new Node(0);
    Node* greaterTail = greaterHead;
    Node* equalHead = new Node(0);
    Node* equalTail = equalHead;
    Node* temp = head;

    while (temp != NULL) {
        int data = temp->data;
        Node* node = new Node(data);
        if (data == x) {
            equalTail->next = node;
            equalTail = equalTail->next;
        }
        else if (data > x) {
            greaterTail->next = node;
            greaterTail = greaterTail->next;
        }
        else {
            lesserTail->next = node;
            lesserTail = lesserTail->next;
        }
        temp = temp->next;
    }

    if (lesserHead->next == NULL) {
        equalTail->next = greaterHead->next;
        return equalHead->next;
    }

    if (equalHead->next == NULL) {
        lesserTail->next = greaterHead->next;
        return lesserHead->next;
    }

    lesserTail->next = equalHead->next;
    equalTail->next = greaterHead->next;

    return lesserHead->next;
}