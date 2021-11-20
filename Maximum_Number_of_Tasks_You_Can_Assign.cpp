#include<bits/stdc++.h>
using namespace std;

int maxHeapRes(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	priority_queue<int> pq(tasks.begin(), tasks.end());
	multiset<int> ms(workers.begin(), workers.end());
    int res = 0;

	while (!pq.empty() && !ms.empty()) {
		int task = pq.top();
		pq.pop();
		auto work = ms.lower_bound(task);
		if (work == ms.end()) {
			if (pills > 0) {
				work = ms.lower_bound(task - strength);
				if (work != ms.end()) {
					++res;
					ms.erase(work);
					--pills;
				}
			}
		}
		else {
			++res;
			ms.erase(work);
		}
	}

	return res;
}

int minHeapRes(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	priority_queue<int, vector<int>, greater<int>> pq(tasks.begin(), tasks.end());
	multiset<int> ms(workers.begin(), workers.end());
	int res = 0;

	while (!pq.empty() && !ms.empty()) {
		int task = pq.top();
		pq.pop();
		auto work = ms.lower_bound(task);
		if (work == ms.end()) {
			if (pills > 0) {
				work = ms.lower_bound(task - strength);
				if (work != ms.end()) {
					++res;
					ms.erase(work);
					--pills;
				}
			}
		}
		else {
			++res;
			ms.erase(work);
		}
	}

	return res;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	priority_queue<int> pq1(tasks.begin(), tasks.end());
	priority_queue<int, vector<int>, greater<int>> pq2(tasks.begin(), tasks.end());
	multiset<int> ms(workers.begin(), workers.end());

	int maxAns = maxHeapRes(tasks, workers, pills, strength);
	int minAns = minHeapRes(tasks, workers, pills, strength);
	int ans = max(maxAns, minAns);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m, pills, strength;
		cin >> n >> m;
		vector<int> tasks(n), workers(m);
		for (int& x : tasks) cin >> x;
		for (int& x : workers) cin >> x;
		cin >> pills >> strength;

		cout << maxTaskAssign(tasks, workers, pills, strength) << endl;
	}

	return 0;
} 