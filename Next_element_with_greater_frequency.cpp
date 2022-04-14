// { Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> print_next_greater_freq(int arr[], int n) {
        // code here
        unordered_map<int, int> count;
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            ++count[arr[i]];
        }

        for (int i = n - 1; i > -1; --i) {
            while (!s.empty() && count[arr[s.top()]] <= count[arr[i]]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : arr[s.top()];
            s.push(i);
        }

        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.print_next_greater_freq(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends