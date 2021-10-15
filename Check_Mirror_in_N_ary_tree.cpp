// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        // code here 
        unordered_map<int, stack<int>> m;

        for (int i = 0; i < 2 * e - 1; i += 2) {
            m[a[i]].push(a[i + 1]);
        }

        for (int i = 0; i < 2 * e - 1; i += 2) {
            if (m[b[i]].top() != b[i + 1]) return 0;
            m[b[i]].pop();
        }

        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;

        cin >> n >> e;
        int* A = new int[2 * e];
        int* B = new int[2 * e];
        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
}  // } Driver Code Ends
