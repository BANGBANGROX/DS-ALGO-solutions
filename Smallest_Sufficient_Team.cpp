#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	typedef long long ll;

	int getSetBitsCount(ll num) {
		int result = 0;

		while (num > 0) {
			if ((num & 1) > 0) ++result;
			num >>= 1;
		}

		return result;
	}

public:
	vector<int> smallestSufficientTeam(vector<string>& requiredSkills,
		vector<vector<string>>& people) {
		int m = (int)requiredSkills.size();
		int n = (int)people.size();
		vector<int> peopleSkillMask(n);
		vector<ll> dp((1 << m), ((ll)1 << n) - 1);
		unordered_map<string, int> skillId;

		for (int i = 0; i < m; ++i) {
			skillId[requiredSkills[i]] = i;
		}

		for (int i = 0; i < n; ++i) {
			for (string& skill : people[i]) {
				peopleSkillMask[i] |= (1 << skillId[skill]);
			}
		}

		dp[0] = 0;

		for (int skillMask = 1; skillMask < (1 << m); ++skillMask) {
			for (int i = 0; i < n; ++i) {
				int smallerSkillMask = skillMask & ~peopleSkillMask[i];
				if (smallerSkillMask != skillMask) {
					ll newMask = dp[smallerSkillMask] | ((ll)1 << i);
					if (getSetBitsCount(newMask) < getSetBitsCount(dp[skillMask])) {
						dp[skillMask] = newMask;
					}
				}
			}
		}

		ll answerMask = dp[(1 << m) - 1];
		vector<int> answer;

		for (int i = 0; i < n; ++i) {
			if ((answerMask & ((ll)1 << i)) > 0) {
				answer.push_back(i);
			}
		}

		return answer;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}