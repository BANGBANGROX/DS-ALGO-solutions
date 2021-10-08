// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/*
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
class Solution {
public:

    void pushNode(Node** head, int x) {
        Node* curr = *head;

        if (curr == NULL) {
            curr = new Node(x);
        }
        else {
            curr->next = new Node(x);
            curr = curr->next;
        }

        *head = curr;
    }

    Node* divide(int n, Node* head) {
        Node* tempHead = head;
        Node* evenHead, * oddHead, * evenTail, * oddTail;
        evenHead = evenTail = oddHead = oddTail = NULL;

        while (tempHead != NULL) {
            int x = tempHead->data;
            if (x % 2 == 0) {
                pushNode(&evenTail, x);
                if (evenHead == NULL) evenHead = evenTail;
            }
            else {
                pushNode(&oddTail, x);
                if (oddHead == NULL) oddHead = oddTail;
            }
            tempHead = tempHead->next;
        }

        Node* res = oddHead;

        if (evenHead != NULL) {
            evenTail->next = oddHead;
            res = evenHead;
        }

        return res;

    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends