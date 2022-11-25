//{ Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> satisfyEqn(int nums[], int n) {
        // code here
        vector<int> ans = { INT_MAX,INT_MAX,INT_MAX,INT_MAX };
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j];
                if (mp.find(sum) != mp.end()) {
                    int a = mp[sum][0];
                    int b = mp[sum][1];
                    if (i != a && j != a && i != b && j != b) {
                        vector<int> current = { a, b, i, j };
                        if (ans > current) {
                            ans = current;
                        }
                    }
                }
                else {
                    mp[sum] = { i,j };
                }
            }
        }

        if (ans[0] == INT_MAX) return { -1,-1,-1,-1 };

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        int* A = new int[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A, N);

        cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] << endl;
    }
    return 0;
}
// } Driver Code Ends