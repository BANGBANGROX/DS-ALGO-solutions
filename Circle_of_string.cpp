// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isCircle(int n, vector<string>& words) {
        // code here
        unordered_map<char, int> charStartCount;
        unordered_map<char, int> charEndCount;
        unordered_map<char, int> charEqualCount;

        for (string& word : words) {
            ++charStartCount[word[0]];
            ++charEndCount[word.back()];
            if (word[0] == word.back()) {
                ++charEqualCount[word[0]];
            }
        }
        
        for (string& word : words) {
            if (charStartCount[word[0]] != charEndCount[word[0]] || 
                (charEqualCount[word[0]] == charStartCount[word[0]] 
                    && charEqualCount[word[0]] != n)) return 0;
        }

        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends