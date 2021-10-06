// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* inputList(int size)
{
    Node* head, * tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node* head1 = inputList(n);
        Node* head2 = inputList(m);

        Node* result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2) {
    // Your Code Here
    Node* tempHead1 = head1, * tempHead2 = head2;
    Node* resList = NULL, * resListTemp = resList;

    while (tempHead1 != NULL && tempHead2 != NULL) {
        int x = tempHead1->data, y = tempHead2->data;
        if (x < y) {
            tempHead1 = tempHead1->next;
            continue;
        }
        else if (x > y) {
            tempHead2 = tempHead2->next;
            continue;
        }
        else {
            if (resList == NULL) {
                resListTemp = new Node(x);
                resList = resListTemp;
            }
            else {
                int back = resListTemp->data;
                if (back != x) {
                    resListTemp->next = new Node(x);
                    resListTemp = resListTemp->next;
                }
            }
            tempHead1 = tempHead1->next;
            tempHead2 = tempHead2->next;
        }
    }

    return resList;
}
