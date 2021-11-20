// { Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

	vector<vector<string>> findSequences(string beginWord, string endWord,
		vector<string>& wordList) {
		// code here
		unordered_set<string> words(wordList.begin(), wordList.end()), vis;
		vector<vector<string>> ans;
		queue<vector<string>> q;

		q.push({ beginWord });

		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				vector<string> currPath = q.front();
				q.pop();
				string lastWord = currPath.back();
				int n = lastWord.size();
				for (int i = 0; i < n; ++i) {
					char letter = lastWord[i];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == letter) continue;
						lastWord[i] = c;
						if (words.find(lastWord) != words.end()) {
							vis.insert(lastWord);
							currPath.push_back(lastWord);
							if (lastWord == endWord) {
								ans.push_back(currPath);
							}
							else q.push(currPath);
							currPath.pop_back();
						}
					}
					lastWord[i] = letter;
				}
			}
			for (auto& str : vis) words.erase(str);
		}

		return ans;
	}
};

// { Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
	string x = "", y = "";
	for (string i : a)
		x += i;
	for (string i : b)
		y += i;

	return x < y;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<string>wordList(n);
		for (int i = 0; i < n; i++) cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if (ans.size() == 0)
			cout << -1 << endl;
		else
		{
			sort(ans.begin(), ans.end(), comp);
			for (int i = 0; i < ans.size(); i++)
			{
				for (int j = 0; j < ans[i].size(); j++)
				{
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}  // } Driver Code Ends
