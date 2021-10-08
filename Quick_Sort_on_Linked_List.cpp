// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct ListNode
{
    int data;
    struct ListNode* next;

    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node = new ListNode(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct ListNode* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct ListNode** headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--) {


        cin >> n; n = n - 1;
        cin >> x;
        ListNode* temp, * head = new ListNode(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);

        }
    }
    return 0;
}// } Driver Code Ends



/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

ListNode* findEnd(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    return temp;
}

ListNode* partition(ListNode* head, ListNode* end, ListNode** newHead, ListNode** newEnd) {
    ListNode* pivot = end, * curr = head, * prev = NULL, * tail = pivot;

    while (curr != pivot) {
        int x = curr->data, y = pivot->data;
        if (x < y) {
            if (*newHead == NULL) {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else {
            if (prev) prev->next = curr->next;
            ListNode* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*newHead == NULL) *(newHead) = pivot;
    *newEnd = tail;

    return pivot;
}

ListNode* sortListUtil(ListNode* head, ListNode* end) {
    if (head == NULL || head == end) return head;

    ListNode* newHead = NULL, * newEnd = NULL;

    ListNode* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        ListNode* beforePivot = newHead;
        while (beforePivot->next != pivot) beforePivot = beforePivot->next;
        beforePivot->next = NULL;
        newHead = sortListUtil(newHead, beforePivot);

        ListNode* temp = findEnd(newHead);
        temp->next = pivot;
    }

    pivot->next = sortListUtil(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct ListNode** headRef) {
    ListNode* head = *headRef;
    ListNode* end = findEnd(head);

    *(headRef) = sortListUtil(head, end);
}
