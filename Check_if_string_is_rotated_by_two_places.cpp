// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	//Function to check if a string can be obtained by rotating
	//another string by exactly 2 places.
	bool isRotated(string s, string t){
		// Your code here
		int m = s.size();
		int n = t.size();

		if (m != n) return false;

		if (m == 1) return s[0] == t[0];

		if (m == 2) return (s[0] == t[1] && s[1] == t[0]);

		// Try left rotate
		int i = 2;
		int j = 0;

		while (j < m) {
			if (t[i] != s[j]) break;
			++j;
			i = (i + 1) % m;
		}

		if (j == m) return true;

		// Try right rotate
		j = 0;
		i = m - 2;

		while (j < m) {
			if (t[i] != s[j]) break;
			++j;
			i = (i + 1) % m;
		}

		return j == m;
	}

};


// { Driver Code Starts.

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		string b;
		cin >> s >> b;
		Solution obj;
		cout << obj.isRotated(s, b) << endl;
	}
	return 0;
}
// } Driver Code Ends