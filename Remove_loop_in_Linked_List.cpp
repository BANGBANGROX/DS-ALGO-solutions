#include <iostream>
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

void loopHere(Node* head, Node* tail, int position)
{
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if (!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

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

*/

class Solution
{
public:
    //Function to remove a loop in the linked list.

    void removeLoopUtil(Node* loopNode, Node* head) {
        Node* ptr1 = loopNode;
        Node* ptr2 = loopNode;

        int nodesInLoop = 1;

        // Find number of nodes in the loop
        while (ptr1->next != ptr2) {
            ptr1 = ptr1->next;
            ++nodesInLoop;
        }

        // Set both to head
        ptr1 = head;
        ptr2 = head;

        // Set ptr2 to nodesInLoop ahead of head
        while (nodesInLoop--) {
            ptr2 = ptr2->next;
        }

        // Both ptr1 and ptr2 will meet at the start of the loop
        // See it like this we have ptr1 at 0 and ptr2 at k-1 (k=nodesInLoop)
        // Now distance of ptr1 to start of loop is n-k and same for ptr2 is 2*(n-k) 
        // So both will meet at the point n-k
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // Now we just find the end of the loop and terminate it
        while (ptr1->next != ptr2) {
            ptr1 = ptr1->next;
        }

        // Terminate the loop
        ptr1->next = NULL;
    }

    void removeLoop(Node* head) {
        if (head == NULL) return;

        Node* slow = head;
        Node* fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow != NULL && fast != NULL && slow == fast) {
                removeLoopUtil(slow, head);
                return;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node* head, * tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
// } Driver Code Ends