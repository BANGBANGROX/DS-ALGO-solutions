//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);

        Node* res = subLinkedList(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/

Node* reverseList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return res;
}

int calculateLength(Node* head) {
    int ans = 0;

    while (head != nullptr) {
        ++ans;
        head = head->next;
    }

    return ans;
}

//You are required to complete this method
Node* subLinkedList(Node* l1, Node* l2) {
    //Your code here
    while (l1 != nullptr && l1->data == 0) l1 = l1->next;

    while (l2 != nullptr && l2->data == 0) l2 = l2->next;

    Node* temp1 = l1;
    Node* temp2 = l2;
    int length1 = calculateLength(temp1);
    int length2 = calculateLength(temp2);
    bool firstGreater = false;

    if (length1 > length2) firstGreater = true;
    if (length1 == length2) {
        while (temp1 != nullptr && temp2 != nullptr && temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == nullptr || temp2 == nullptr) return new Node(0);
        firstGreater = temp1->data > temp2->data;
    }
    
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    if (firstGreater) {
        temp1 = l1;
        temp2 = l2;
    }
    else {
        temp1 = l2;
        temp2 = l1;
    }

    int carry = 0;

    while (temp1 != nullptr && temp2 != nullptr) {
        temp1->data = temp1->data - carry;
        if (temp1->data < temp2->data) {
            temp1->data = temp1->data + 10 - temp2->data;
            carry = 1;
        }
        else {
            temp1->data = temp1->data - temp2->data;
            carry = 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr) {
        if (carry > 0) {
            if (temp1->data < carry) {
                temp1->data = temp1->data + 10 - carry;
            }
            else {
                temp1->data = temp1->data - carry;
                carry = 0;
            }
        }
        temp1 = temp1->next;
    }

    Node* ans = nullptr;

    if (firstGreater) ans = reverseList(l1);
    else ans = reverseList(l2);

    while (ans != nullptr && ans->data == 0) ans = ans->next;

    return ans;
}