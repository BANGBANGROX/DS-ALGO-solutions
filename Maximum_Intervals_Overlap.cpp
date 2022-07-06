// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> findMaxGuests(int entry[], int exit[], int n) {
        // Your code goes here
        sort(entry, entry + n);
        sort(exit, exit + n);

        int i = 1;
        int j = 0;
        int currentIntervals = 1;
        vector<int> ans = { 1, entry[0] };

        while (i < n && j < n) {
            if (entry[i] <= exit[j]) {
                ++currentIntervals;
                if (ans[0] < currentIntervals) {
                    ans = { currentIntervals,entry[i] };
                }
                ++i;
            }
            else {
                --currentIntervals;
                ++j;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int* entry = new int[n], * exit1 = new int[n];
        for (i = 0; i < n; i++)
            cin >> entry[i];
        for (i = 0; i < n; i++)
            cin >> exit1[i];
        Solution obj;

        vector<int> p = obj.findMaxGuests(entry, exit1, n);
        cout << p[0] << ' ' << p[1];
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends