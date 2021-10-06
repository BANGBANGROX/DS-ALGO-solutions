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
        cout << node->data;
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

class Solution
{
public:
    Node* reverseList(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if (head == NULL) return head;

        Node* tempNode = head;
        tempNode = reverseList(tempNode);
        Node* newList = NULL, * newListTemp = newList;
        int carry = 0;

        int data = tempNode->data + 1;
        carry = data / 10;
        int ans = data % 10;
        newListTemp = new Node(ans);
        newList = newListTemp;
        tempNode = tempNode->next;

        while (tempNode != NULL) {
            int value = carry + tempNode->data;
            int ans = value % 10;
            carry = value / 10;
            newListTemp->next = new Node(ans);
            newListTemp = newListTemp->next;
            tempNode = tempNode->next;
        }
        if (carry) {
            newListTemp->next = new Node(carry);
            newListTemp = newListTemp->next;
        }

        newList = reverseList(newList);

        return newList;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node* head = new Node(s[0] - '0');
        Node* tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
