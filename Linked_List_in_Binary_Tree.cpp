#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSubPathUtil(ListNode* head, TreeNode* root) {
    if (head == NULL) return true;
    
    if (root == NULL) return false;

    if (head->val == root->val) head = head->next;
    else return false;

    return isSubPathUtil(head, root->left) || isSubPathUtil(head, root->right);
}

bool isSubPath(ListNode* head, TreeNode* root) {
    if (head == NULL) return true;

    if (root == NULL) return false;
     
    if (head->val == root->val) {
        if (isSubPathUtil(head, root)) return true;
    }

    return isSubPath(head, root->left) || isSubPath(head, root->right);
}