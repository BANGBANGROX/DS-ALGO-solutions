// { Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> TopK(vector<int>& array, int k) {
        // code here
        unordered_map<int, int> frequency;
        vector<int> ans;
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for (int x : array) {
            ++frequency[x];
        }

        for (const pair<int, int> x : frequency) {
            //cout << x.first << " " << x.second << endl;
            if (pq.size() < k) pq.push({ x.second, x.first });
            else {
                pair<int, int> current = pq.top();
                if (x.second >= current.first) {
                    if (x.second > current.first) {
                        pq.pop();
                        pq.push({ x.second, x.first });
                    }
                    else if (x.first > current.second) {
                        pq.pop();
                        pq.push({ x.second, x.first });
                    }
                }
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

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
        int n, k;
        cin >> n;

        vector<int>array(n);

        for (int i = 0; i < n; i++)
            cin >> array[i];

        cin >> k;

        Solution obj;
        vector<int> result = obj.TopK(array, k);

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";

        cout << "\n";

    }
    return 0;
}  // } Driver Code Ends