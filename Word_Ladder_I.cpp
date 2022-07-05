// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
		// Code here
		unordered_set<string> dictionary(wordList.begin(), wordList.end());
		int length = 1;

		if (dictionary.find(targetWord) == dictionary.end()) return 0;

		if (targetWord.compare(startWord) == 0) return 1;

		queue<string> q;

		q.push(startWord);
		dictionary.erase(startWord);

		while (!q.empty()) {
			int n = q.size();
			for (int j = 0; j < n; ++j) {
				string currentWord = q.front();
				q.pop();
				int len = currentWord.size();
				for (int i = 0; i < len; ++i) {
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						char prev = currentWord[i];
						currentWord[i] = ch;
						if (currentWord.compare(targetWord) == 0) return length + 1;
						if (dictionary.find(targetWord) != dictionary.end()) {
							q.push(currentWord);
							dictionary.erase(currentWord);
						}
						currentWord[i] = prev;
					}
				}
			}
			++length;
		}

		return 0;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<string>wordList(n);
		for (int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends