// { Driver Code Starts
#include <iostream>

// https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1#

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



Node* swapkthnode(Node* head, int num, int K);

void addressstore(Node** arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node** before, Node** after, int num, int K)
{
    if (K > num)
        return 1;
    return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for (int i = 0; i < num - 1; i++) {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node** before = new Node * [num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node** after = new Node * [num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node* swapkthnode(Node* head, int n, int k) {
    // Your Code here
    if (k > n || n == 1) return head;

    int start = k;
    int end = n - k + 1;
    int ind = 1;
    Node* prevFirst = NULL;
    Node* first = head;
    Node* prevLast = NULL;
    Node* last = head;
    Node* tempHead = head;
    Node* prev = NULL;
    
    while (tempHead != NULL) {
        if (ind == start) {
            prevFirst = prev;
            first = tempHead;
        }
        if (ind == end) {
            prevLast = prev;
            last = tempHead;
            break;
        }
        ++ind;
        prev = tempHead;
        tempHead = tempHead->next;
    }

    if (first == last) return head;

    if (first->next == last) {
        prevFirst->next = last;
        first->next = last->next;
        last->next = first;
        return head;
    }

    if (prevFirst != NULL) {
        Node* nextFirst = first->next;
        Node* nextLast = last->next;
        prevFirst->next = last;
        prevLast->next = first;
        last->next = nextFirst;
        first->next = nextLast;
        return head;
    }

    Node* nextFirst = first->next;
    Node* nextLast = last->next;
    prevLast->next = first;
    last->next = nextFirst;
    first->next = nextLast;

    return head;
}
