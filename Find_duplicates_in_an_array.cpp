//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> duplicates(int nums[], int n) {
        // code here
        vector<int> answer;
        vector<int> count(n);

        for (int i = 0; i < n; ++i) {
            ++count[nums[i]];
        }

        for (int i = 0; i < n; ++i) {
            if (count[i] > 1) {
                answer.push_back(i);
            }
        }

        if (answer.empty()) {
            answer.push_back(-1);
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends