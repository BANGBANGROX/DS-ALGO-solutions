// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution {
public:

    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
        //code here
        int minValue = INT_MAX, maxValue = INT_MIN, minRange = INT_MAX, start = -1, end = -1;
        priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < k; ++i) {
            pq.push({ KSortedArray[i][0],{i,1} });
            maxValue = max(maxValue, KSortedArray[i][0]);
        }
        
        while (true) {
            pair<int, pair<int, int>> root = pq.top();
            pq.pop();
            minValue = root.first;
            if (minRange > maxValue - minValue + 1) {
                start = minValue;
                end = maxValue;
                minRange = end - start + 1;
            }
            int i = root.second.first, j = root.second.second;
            if (j < n) {
                root.first = KSortedArray[i][j];
                ++j;
                maxValue = max(maxValue, root.first);
            }
            else break;
            root.second.second = j;
            pq.push(root);
        }

        return { start,end };
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
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

