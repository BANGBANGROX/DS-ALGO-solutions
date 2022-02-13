#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		int n = nums.size();
		int ones = 0;
		int zeroes = 0;
		int maxScore = 0;
		vector<int> prefixOnes(n);
		vector<int> prefixZeroes(n);
		vector<int> scores;
		vector<int> ans;

		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0) ++zeroes;
			else ++ones;
			prefixOnes[i] = ones;
			prefixZeroes[i] = zeroes;
		}

		scores.push_back(ones);
		maxScore = max(maxScore, ones);
		
		for (int i = 1; i < n; ++i) {
			int leftScore = prefixZeroes[i - 1];
			int rightScore = prefixOnes[n - 1] - prefixOnes[i - 1];
			int score = leftScore + rightScore;
			scores.push_back(score);
			maxScore = max(maxScore, score);
		}

		scores.push_back(zeroes);
		maxScore = max(maxScore, zeroes);

		for (int i = 0; i < scores.size(); ++i) {
			if (scores[i] == maxScore) {
				ans.push_back(i);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		vector<int> ans = solution.maxScoreIndices(nums);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}