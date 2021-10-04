#include<bits/stdc++.h>
using namespace std;
struct trienode
{
	trienode* left;
	trienode* right;
};
void insert(trienode* root, int x)
{
	trienode* temp = root;
	for (int i = 30; i > -1; i--)
	{
		int val = (x >> i) & 1;
		if (val == 0)
		{
			if (temp->left == NULL) temp->left = new trienode();
			temp = temp->left;
		}
		else
		{
			if (temp->right == NULL) temp->right = new trienode();
			temp = temp->right;
		}
	}
}
int maxxor(int a[], int n, trienode* root)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int curr = 0, m = (1 << 30);
		trienode* temp = root;
		for (int j = 30; j > -1; j--)
		{
			int val = (a[i] >> j) & 1;
			if (val == 0)
			{
				if (temp->right)
				{
					curr += m;
					temp = temp->right;
				}
				else temp = temp->left;
			}
			else
			{
				if (temp->left)
				{
					curr += m;
					temp = temp->left;
				}
				else temp = temp->right;
			}
			m /= 2;
		}
		res = max(res, curr);
	}
	return res;
}
int main()
{
	int n, a[10005];
	cin >> n;
	trienode* root = new trienode();
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(root, a[i]);
	}
	cout << maxxor(a, n, root) << "\n";
	return 0;
}