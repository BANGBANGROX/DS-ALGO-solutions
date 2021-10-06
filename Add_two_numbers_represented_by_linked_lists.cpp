// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    struct Node* revereList(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* rest = revereList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        // code here
        Node* revFirst = revereList(first);
        Node* revSecond = revereList(second);
        Node* resList = NULL, * resListTemp = resList;
        int carry = 0;

        while (revFirst != NULL && revSecond != NULL) {
            int x = revFirst->data, y = revSecond->data;
            int value = x + y + carry;
            carry = value / 10;
            value %= 10;
            if (resList == NULL) {
                resListTemp = new Node(value);
                resList = resListTemp;
            }
            else {
                resListTemp->next = new Node(value);
                resListTemp = resListTemp->next;
            }
            revFirst = revFirst->next;
            revSecond = revSecond->next;
        }

        while (revFirst != NULL) {
            int x = revFirst->data;
            int value = x + carry;
            carry = value / 10;
            value %= 10;
            if (resList == NULL) {
                resListTemp = new Node(value);
                resList = resListTemp;
            }
            else {
                resListTemp->next = new Node(value);
                resListTemp = resListTemp->next;
            }
            revFirst = revFirst->next;
        }

        while (revSecond != NULL) {
            int x = revSecond->data;
            int value = x + carry;
            carry = value / 10;
            value %= 10;
            if (resList == NULL) {
                resListTemp = new Node(value);
                resList = resListTemp;
            }
            else {
                resListTemp->next = new Node(value);
                resListTemp = resListTemp->next;
            }
            revSecond = revSecond->next;
        }
        if (carry) {
            resListTemp->next = new Node(carry);
            resListTemp = resListTemp->next;
        }

        resList = revereList(resList);

        return resList;
    }
};


// { Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends
