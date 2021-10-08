// { Driver Code Starts
/* Program to split a circular linked list into two halves */


#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>

/* structure for a Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref);
struct Node* newNode(int key)
{
    struct Node* temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of
    the two resultant linked lists */

void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL)
    {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}


/* Driver program to test above functions */
int main()
{

    int t, n, i, x;
    scanf_s("%d", &t);
    while (t--)
    {
        struct Node* temp, * head = NULL;
        struct Node* head1 = NULL;
        struct Node* head2 = NULL;
        scanf_s("%d", &n);
        scanf_s("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            scanf_s("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;

        }

        temp->next = head;

        splitList(head, &head1, &head2);

        // printf("\nFirst Circular Linked List");
        printList(head1);

        // printf("\nSecond Circular Linked List");
        printList(head2);

    }
    return 0;
}
// } Driver Code Ends


/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

Node* findEnd(Node* head) {
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    return temp;
}

void splitList(Node* head, Node** headRef1, Node** headRef2) {
    // your code goes here
    Node* slow = head, * fast = slow;
    Node* end = findEnd(head);

    while (fast != end && fast->next != end) {
        std::cout << "in loop";
        slow = slow->next;
        fast = fast->next->next;
    }

    *headRef2 = slow->next;
    end->next = *headRef2;

    *headRef1 = head;
    slow->next = *headRef1;
}
