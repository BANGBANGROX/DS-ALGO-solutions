#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to create a new Node with given data */
struct Node* newNode(int data)
{
    struct Node* new_Node = new Node(data);

    return new_Node;
}


Node* reverse(Node** r)
{
    Node* prev = NULL;
    Node* cur = *r;
    Node* nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}


void freeList(struct Node* Node)
{
    struct Node* temp;
    while (Node != NULL)
    {

        temp = Node;
        Node = Node->next;
        free(temp);
    }

}


/* Multiply contents of two linked lists */
long long  multiplyTwoLists(struct Node*, struct Node*);

// A utility function to print a linked list
void printList(struct Node* Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{


    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {

        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first, second);

        cout << res << endl;
        freeList(first);
        freeList(second);

    }
    return 0;
}
// } Driver Code Ends


/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/

const ll mod = 1e9 + 7;

ll findPow(ll a, ll b) {
    if (b == 0) return 1;

    ll res = 1;

    while (b) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
            --b;
        }
        a = (a * a) % mod;
        b /= 2;
    }

    return res;
}

int findLength(Node* head) {
    Node* temp = head;
    int len = 0;

    while (temp != NULL) {
        ++len;
        temp = temp->next;
    }

    return len;
}

ll findNum(Node* head) {
    Node* a = head;
    ll num = 0;
    int cnt = 0;
    int len = findLength(a);

    while (a != NULL) {
        int y = a->data;
        num = (num + ((ll)y * findPow(10, (ll)len - cnt - 1)) % mod) % mod;
        ++cnt;
        a = a->next;
    }

    return num;
}

ll multiplyTwoLists(Node* l1, Node* l2) {
    //Your code here
    ll num1 = findNum(l1);
    ll num2 = findNum(l2);

    ll ans = (num1 * num2) % mod;

    return ans;
}