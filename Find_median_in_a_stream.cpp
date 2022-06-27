// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    //Function to insert heap.
    void insertHeap(int& x) {
        if (!maxHeap.empty() && x > maxHeap.top()) minHeap.push(x);
        else maxHeap.push(x);

        balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps() {
        if (abs((int)maxHeap.size() - (int)minHeap.size()) <= 1) return;

        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    //Function to return Median.
    double getMedian() {
        if ((int)maxHeap.size() == (int)minHeap.size()) return ((long)maxHeap.top() + minHeap.top()) / 2.0;

        if ((int)maxHeap.size() > (int)minHeap.size()) return maxHeap.top();

        return minHeap.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}  // } Driver Code Ends