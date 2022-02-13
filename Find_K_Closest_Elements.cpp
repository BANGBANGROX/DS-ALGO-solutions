#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> ans;
		priority_queue<pair<int, int>> pq;

		for (int num : arr) {
			if (pq.size() < k) pq.push({ abs(x - num),num });
			else {
				int diff = abs(x - num);
				pair<int, int> curr = pq.top();
				if (curr.first >= diff) {
					if (curr.first > diff) {
						pq.pop();
						pq.push({ diff,num });
					}
					else if (curr.second > num) {
						pq.pop();
						pq.push({ diff,num });
					}
				}
			}
		}

		while (!pq.empty()) {
			ans.push_back(pq.top().second);
			pq.pop();
		}

		sort(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k, x;
		cin >> n;
		vector<int> arr(n);
		for (int& x : arr) cin >> x;
		cin >> k >> x;

		Solution solution;
		vector<int> ans = solution.findClosestElements(arr, k, x);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}