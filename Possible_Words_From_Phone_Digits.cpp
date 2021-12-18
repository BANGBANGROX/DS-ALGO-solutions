// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	vector<string> letters{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ans;
	int n = 0;

	void generate(int index, string& curr, int a[]) {
		if (index == n) {
			ans.push_back(curr);
			return;
		}

		for (int i = 0; i < letters[a[index] - 2].size(); ++i) {
			curr += letters[a[index] - 2][i];
			generate(index + 1, curr, a);
			curr.pop_back();
		}
	}

	//Function to find list of all words possible by pressing given numbers.
	vector<string> possibleWords(int a[], int n){
		//Your code here
		this->n = n;
		string curr("");

		generate(0, curr, a);

		return ans;
	}
};


// { Driver Code Starts.

int main() {

	int T;

	cin >> T; //testcases

	while (T--) { //while testcases exist
		int N;

		cin >> N; //input size of array

		int* a = new int[N]; //declare the array

		for (int i = 0; i < N; i++) {
			cin >> a[i]; //input the elements of array that are keys to be pressed
		}

		Solution obj;

		vector <string> res = obj.possibleWords(a, N);
		for (string i : res) cout << i << " ";
		cout << endl;
	}

	return 0;
}  // } Driver Code Ends
