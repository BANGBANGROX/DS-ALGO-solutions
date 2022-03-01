// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    typedef long long ll;

    string prefixMatch(string res, string num) {
        if (num.size() > res.size()) return "";

        int i = 0;

        while (i < num.size() && num[i] == res[i]) {
            ++i;
        }

        if (i != num.size()) return "";

        return res.substr(i);
    }

public:
    ll countPairs(int n, int x, vector<int> numbers) {
        // code here
        string res = to_string(x);
        unordered_map<string, int> count;
        ll ans = 0;

        for (int& num : numbers) {
            ++count[to_string(num)];
        }

        for (int& num : numbers) {
            string stringNum = to_string(num);
            if (count[stringNum] == 0) continue;
            string suffix = prefixMatch(res, stringNum);
            if (suffix.compare("") == 0 || count.find(suffix) == count.end()) continue;
            if (stringNum.compare(suffix) == 0) {
                ans += ((ll)count[suffix] - 1);
            }
            else {
                ans += (ll)count[suffix];
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N >> X;
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout << ans << endl;

    }

    return 0;
}  // } Driver Code Ends