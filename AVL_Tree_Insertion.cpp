//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if(!n) return 1;
    if( n->data <= lower || n->data >= upper ) return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
    if(!n) return pair<int,bool> (0,1);

    pair<int,bool> l = isBalanced(n->left);
    pair<int,bool> r = isBalanced(n->right);

    if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

    return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
    if( !isBST(root, INT_MIN, INT_MAX) )
        cout<< "BST voilated, inorder traversal : ";

    else if ( ! isBalanced(root).second )
        cout<< "Unbalanced BST, inorder traversal : ";

    else return 1;
    return 0;
}

void printInorder(Node* n)
{
    if(!n) return;
    printInorder(n->left);
    cout<< n->data << " ";
    printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
    int getHeight(Node *node) {
        if (node == nullptr) return 0;

        return node->height;
    }

    int getBalancingFactor(Node *node) {
        if (node == nullptr) return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    Node *leftRotate(Node *node) {
        Node *right = node->right;
        Node *left = right->left;

        right->left = node;
        node->right = left;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

        return right;
    }

    Node *rightRotate(Node *node) {
        Node *left = node->left;
        Node *right = left->right;

        left->right = node;
        node->left = right;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

        return left;
    }

public:
    /*You are required to complete this method */
    Node *insertToAVL(Node *node, int data) {
        //Your code here
        if (node == nullptr) return new Node(data);

        if (data > node->data) node->right = insertToAVL(node->right, data);
        else if (data < node->data) node->left = insertToAVL(node->left, data);
        else return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balancing = getBalancingFactor(node);

        // LL Case
        if (balancing > 1 && data < node->left->data) {
            return rightRotate(node);
        }

        // RR Case
        if (balancing < -1 && data > node->right->data) {
            return leftRotate(node);
        }

        // LR Case
        if (balancing > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balancing < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};

//{ Driver Code Starts.

int main() {
    int ip[MAXN];

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> ip[i];

        Node *root = NULL;
        Solution obj;
        for (int i = 0; i < n; i++) {
            root = obj.insertToAVL(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        printInorder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends