//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> leafNodes(int nums[], int n) {
        // code here
        vector<int> ans;
        stack<int> st;

        st.push(nums[0]);

        for (int i = 1; i < n; ++i) {
            if (nums[i] < st.top()) st.push(nums[i]);
            else {
                int num = st.top();
                int size = st.size();
                while (!st.empty() && nums[i] > st.top()) st.pop();
                st.push(nums[i]);
                if (size > st.size()) ans.push_back(num);
            }
        }

        ans.push_back(st.top());

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int* arr = new int[N];
        for (int i = 0; i < N; i++)cin >> arr[i];
        Solution ob;
        vector<int>ans = ob.leafNodes(arr, N);
        for (int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends