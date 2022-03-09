#include<bits/stdc++.h>
using namespace std;

class Solution {
	struct Job {
		int start;
		int end;
		int profit;

		Job(int start, int end, int profit) {
			this->start = start;
			this->end = end;
			this->profit = profit;
		}
	};

	vector<int> dp;

	int jobSchedulingUtil(int index, vector<Job>& jobs) {
		if (index == jobs.size()) return 0;

		if (dp[index] != -1) return dp[index];

		int n = jobs.size();
		int nextIndex = n;
		int l = 0;
		int r = n - 1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (jobs[mid].start >= jobs[index].end) {
				nextIndex = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		int ans;

		// Let's pick the current event
		ans = jobs[index].profit + jobSchedulingUtil(nextIndex, jobs);
		
		// Let's leave the current event
		ans = max(ans, jobSchedulingUtil(index + 1, jobs));

		return dp[index] = ans;
	}

public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = endTime.size();
		vector<Job> jobs;

		for (int i = 0; i < n; ++i) {
			jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
		}

		sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) {return a.start < b.start; });

		dp = vector<int>(n, -1);

		return jobSchedulingUtil(0, jobs);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> startTime(n), endTime(n), profit(n);
		for (int& x : startTime) cin >> x;
		for (int& x : endTime) cin >> x;
		for (int& x : profit) cin >> x;

		Solution solution;
		cout << solution.jobScheduling(startTime, endTime, profit) << endl;
	}

	return 0;
}