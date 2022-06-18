// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
struct Box {
    int length;
    int width;
    int height;
};

class Solution {
public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(int height[], int width[], int length[], int n) {
        //Your code here
        vector<Box> boxes(6 * n);
        vector<int> dp(6 * n);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            boxes[i] = { length[i], width[i], height[i] };
            boxes[i + n] = { length[i], height[i], width[i] };
            boxes[i + 2 * n] = { width[i], length[i], height[i] };
            boxes[i + 3 * n] = { width[i], height[i], length[i] };
            boxes[i + 4 * n] = { height[i], length[i], width[i] };
            boxes[i + 5 * n] = { height[i], width[i], length[i] };
        }

        sort(boxes.begin(), boxes.end(), [](Box a, Box b) {
            return a.length * a.width < b.length * b.width;
            });

        for (int i = 0; i < 6 * n; ++i) {
            int maxValue = 0;
            for (int j = 0; j < i; ++j) {
                if (boxes[j].length > boxes[i].length && boxes[j].width > boxes[i].width) {
                    maxValue = max(maxValue, dp[j]);
                }
            }
            dp[i] = maxValue + boxes[i].height;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;


        int A[105], B[105], C[105];
        for (int i = 0; i < n; i++)cin >> A[i];
        for (int j = 0; j < n; j++)cin >> B[j];
        for (int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout << ob.maxHeight(A, B, C, n) << endl;
    }

    return 0;
}
// } Driver Code Ends