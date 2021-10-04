#include<bits/stdc++.h>
using namespace std;
struct trienode
{
	trienode* left;
	trienode* right;
};
void insert(int x, trienode* root)
{
	trienode* temp = root;
	for (int i = 30; i > -1; i--)
	{
		int val = (x >> i) & 1;
		if (val == 0)
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
}
int maxxor(int x, trienode* root)
{
	int res = 0;
	trienode* temp = root;
	for (int i = 30; i > -1; i--)
	{
		int val = (x >> i) & 1;
		if (!temp->left && !temp->right) return -1;
		if (val == 0)
		{
			if (temp->right)
			{
				res += (1 << i);
				temp = temp->right;
			}
			else temp = temp->left;
		}
		else
		{
			if (temp->left)
			{
				res += (1 << i);
				temp = temp->left;
			}
			else temp = temp->right;
		}
	}
	return res;
}
class solution
{
 public:
	 vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
	 {
		 trienode* root = new trienode();
		 sort(nums.begin(), nums.end());
		 int q = queries.size(), n = nums.size();
		 vector<int> res(q, 0);
		 for (int i = 0; i < q; i++) queries[i].push_back(i);
		 sort(queries.begin(), queries.end(), [](auto& q1, auto& q2) {
			 return q1[1] < q2[1];
			 });
		 int ind = 0;
		 for (auto& query : queries)
		 {
			 while (ind < n && nums[ind] <= query[1])
			 {
				 insert(nums[ind], root);
				 ind++;
			 }
			 res[query[2]] = maxxor(query[0], root);
		 }
		 return res;
	 }
};
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<vector<int>> queries;
	while (q--)
	{
		int num, x;
		cin >> num >> x;
		queries.push_back({ num,x });
	}
	solution sol;
	vector<int> res = sol.maximizeXor(a, queries);
	for (int x : res) cout << x << "\n";
	return 0;
}
