#include<bits/stdc++.h>
using namespace std;

struct minHeapNode {
	char data;
	int freq;
	minHeapNode* left;
	minHeapNode* right;
	minHeapNode(char data, int freq) {
		this->data = data;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};

struct compare {
	bool operator()(minHeapNode* l, minHeapNode* r) {
		return l->freq > r->freq;
	}
};

void preorder(minHeapNode* root, string str, vector<string>& res) {
	if (!root) return;
	if (root->data != '$') res.push_back(str);
	preorder(root->left, str + '0', res);
	preorder(root->right, str + '1', res);
}

vector<string> huffmanCodes(string S, vector<int>& f, int n) {
	priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;
	minHeapNode* left, * right, * top;
	vector<string> res;

	for (int i = 0; i < n; ++i) {
		minHeap.push(new minHeapNode(S[i], f[i]));
	}
	while (minHeap.size() > 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new minHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	preorder(minHeap.top(), "", res);

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> freq(n);
		for (int& x : freq) cin >> x;

		vector<string> ans = huffmanCodes(s, freq, n);
		for (string res : ans) cout << res << endl;
	}

	return 0;
}