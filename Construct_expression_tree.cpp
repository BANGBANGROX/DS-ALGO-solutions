// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, * right;

	et(char x) {
		value = x;
		left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
		c == '*' || c == '/' ||
		c == '^')
		return true;
	return false;
}

void inorder(et* t)
{
	if (t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char[]);

int main()
{
	int t;
	cin >> t;
	while (t--) {
		char postfix[25];
		cin >> postfix;
		et* r = constructTree(postfix);
		inorder(r);
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

et* constructTreeUtil(string infix, int l, int r) {
	if (l > r) return NULL;

	int mid = (l + r) / 2;

	et* root = new et(infix[mid]);

	root->left = constructTreeUtil(infix, l, mid - 1);
	root->right = constructTreeUtil(infix, mid + 1, r);

	return root;
}

//function to construct expression tree
et* constructTree(char postfix[]) {
	//code here
	int n = strlen(postfix);
	stack<string> st;

	for (int i = 0; i < n; ++i) {
		if (!isOperator(postfix[i])) {
			string temp("");
			st.push(temp + postfix[i]);
		}
		else {
			string b = st.top();
			st.pop();
			string a = st.top();
			st.pop();
			st.push(a + postfix[i] + b);
		}
	}

	string infix = st.top();

	cout << infix << endl;

	return constructTreeUtil(infix, 0, n - 1);
}

