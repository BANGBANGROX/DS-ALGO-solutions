// https://leetcode.com/problems/range-sum-query-mutable/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
    struct SegmentTreeNode {
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;

        SegmentTreeNode(int start, int end) {
            this->start = start;
            this->end = end;
            sum = 0;
            left = right = NULL;
        }
    };

    SegmentTreeNode* root = NULL;

    SegmentTreeNode* buildTree(int start, int end, vector<int>& nums) {
        SegmentTreeNode* currentNode = new SegmentTreeNode(start, end);

        if (start == end) {
            currentNode->sum = nums[start];
            return currentNode;
        }

        int mid = (start + ((end - start) >> 1));

        currentNode->left = buildTree(start, mid, nums);
        currentNode->right = buildTree(mid + 1, end, nums);

        currentNode->sum = currentNode->left->sum + currentNode->right->sum;

        return currentNode;
    }

    void updateTree(SegmentTreeNode* root, int pos, int value) {
        if (root->start == pos && root->end == pos) {
            root->sum = value;
            return;
        }

        int mid = (root->start + ((root->end - root->start) >> 1));

        if (pos <= mid) {
            updateTree(root->left, pos, value);
        }
        else {
            updateTree(root->right, pos, value);
        }

        root->sum = root->left->sum + root->right->sum;
    }

    int queryTree(int left, int right, SegmentTreeNode* root) {
        if (root->start == left && root->end == right) return root->sum;

        int mid = (root->start + ((root->end - root->start) >> 1));

        if (right <= mid) return queryTree(left, right, root->left);

        if (left > mid) return queryTree(left, right, root->right);

        return queryTree(left, mid, root->left) + queryTree(mid + 1, right, root->right);
    }

public:
    NumArray(vector<int>& nums) {
        root = buildTree(0, nums.size() - 1, nums);
    }

    void update(int index, int val) {
        updateTree(root, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(left, right, root);
    }
};

int main() {
    vector<int> nums = { 1,3,5 };
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl; // return 1 + 3 + 5 = 9
    numArray.update(1, 2);   // nums = [1, 2, 5]
    cout << numArray.sumRange(0, 2) << endl; // return 1 + 2 + 5 = 8

	return 0;
}