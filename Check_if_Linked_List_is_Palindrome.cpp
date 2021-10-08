// { Driver Code Starts
#include<bits/stdc++.h>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
public:
    //Function to check whether the list is palindrome.
    void reverseList(Node** headRef) {
        Node* head = *headRef;
        Node* curr = head, * prev = NULL, * next = curr;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        *headRef = prev;
    }

    bool compareLists(Node* list1, Node* list2) {
        Node* a = list1, * b = list2;

        while (a != NULL && b != NULL) {
            int x = a->data, y = b->data;
            if (x != y) return false;
            a = a->next;
            b = b->next;
        }

        return true;
    }

    void parition(Node* head, Node** firstHalf, Node** secondHalf) {
        Node* slow = head, * fast = slow, * prevSlow = slow;

        while (fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL) {
            slow = slow->next;
        }

        *(firstHalf) = head;
        prevSlow->next = NULL;

        *(secondHalf) = slow;
    }

    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) return true;

        Node* firstHalf = NULL, * secondHalf = NULL;

        parition(head, &firstHalf, &secondHalf);

        reverseList(&secondHalf);

        return compareLists(firstHalf, secondHalf);
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node* head = NULL, * tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends