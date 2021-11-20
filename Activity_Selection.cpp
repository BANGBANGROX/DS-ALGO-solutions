// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:

    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second) return a.second < b.second;

        return a.first < b.first;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // Your code here
        vector<pair<int, int>> intervals(n);
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            intervals[i] = { start[i],end[i] };
        }

        sort(intervals.begin(), intervals.end(), comp);

        int last = intervals[0].second;

        for (int i = 1; i < n; ++i) {
            //cout << intervals[i].first << " " << intervals[i].second << endl;
            if (intervals[i].first > last) {
                ++ans;
                last = intervals[i].second;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;

    //testcases
    cin >> t;
    while (t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
