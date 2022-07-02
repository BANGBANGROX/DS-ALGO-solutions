// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

class Solution {
    string s;

    Node* constructTree(int index) {
        if (index >= (int)s.size() || !isdigit(s[index])) return NULL;

        string value("");

        while (index < (int)s.size() && isdigit(s[index])) {
            value += s[index];
            ++index;
        }

        Node* root = new Node(stoi(value));

        if (index == (int)s.size() || s[index] == ')') return root;

        root->left = constructTree(index + 1);

        ++index;
        int currentSum = 1;

        while (index < (int)s.size()) {
            if (s[index] == '(') ++currentSum;
            else if (s[index] == ')') --currentSum;
            if (currentSum == 0) break;
            ++index;
        }

        if (index == (int)s.size()) return root;

        root->right = constructTree(index + 1);

        return root;
    }

public:
    // function to construct tree from string
    Node* treeFromString(string s) {
        // code here
        this->s = s;

        return constructTree(0);
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node* root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends