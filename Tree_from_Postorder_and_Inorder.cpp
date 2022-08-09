//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int* in = new int[n], * post = new int[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int findIndex(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; ++i) {
        if (inorder[i] == key) return i;
    }

    return -1;
}

Node* buildTreeUtil(int inorder[], int postorder[], int start, int end, int& index) {
    if (start > end) return NULL;

    Node* root = new Node(postorder[index]);
    --index;

    int idx = findIndex(inorder, start, end, root->data);

    root->right = buildTreeUtil(inorder, postorder, idx + 1, end, index);
    root->left = buildTreeUtil(inorder, postorder, start, idx - 1, index);

    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node* buildTree(int inorder[], int postorder[], int n) {
    // Your code here
    int index = n - 1;

    return buildTreeUtil(inorder, postorder, 0, n - 1, index);
}