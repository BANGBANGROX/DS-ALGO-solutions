#include<bits/stdc++.h>
using namespace std;
struct trienode
{
	int val;
	trienode* left;
	trienode* right;
};
void insert(int x, trienode* root)
{
	trienode* temp = root;
	for (int i = 30; i > -1; i--)
	{
		int t = (x >> i) & 1;
		if (t == 0)
		{
			if (!temp->left) temp->left = new trienode();
			temp = temp->left;
		}
		else
		{
			if (!temp->right) temp->right = new trienode();
			temp = temp->right;
		}
	}
	temp->val = x;
}
int minxorret(int x, trienode* root)
{
	trienode* temp = root;
	for (int i = 30; i > -1; i--)
	{
		int t = (x >> i) & 1;
		if (!temp->left && !temp->right) return INT_MAX;
		if (t == 0)
		{
			if (temp->left) temp = temp->left;
			else temp = temp->right;
		}
		else
		{
			if (temp->right) temp = temp->right;
			else temp = temp->left;
		}
	}
	return x ^ temp->val;
}
int minxor(int a[], int n)
{
	int res = INT_MAX;
	trienode* root = new trienode();
	for (int i = 0; i < n; i++)
	{
		res = min(res, minxorret(a[i], root));
		insert(a[i], root);
	}
	return res;
}
int main()
{
	int n, a[10002];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << minxor(a, n) << "\n";
	return 0;
}
