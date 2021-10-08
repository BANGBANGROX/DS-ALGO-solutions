// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node* head = NULL, * tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.

int findLength(Node* head) {
    int len = 0;

    while (head != NULL) {
        ++len;
        head = head->next;
    }

    return len;
}

int getNthFromLast(Node* head, int n) {
    // Your code here

    int cnt = 0, len = findLength(head);

    n = len - n + 1;

    while (head != NULL && cnt < n) {
        ++cnt;
        if (cnt == n) return head->data;
        head = head->next;
    }

    return -1;
}


