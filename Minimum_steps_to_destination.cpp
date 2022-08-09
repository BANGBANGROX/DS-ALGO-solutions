//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minSteps(int target) {
        // code here
        int currentState = 0;
        int step = 1;

        while (currentState < target) {
            currentState += step;
            ++step;
        }

        --step;

        int diff = currentState - target;

        if ((diff & 1) == 0) return step;

        ++step;
        currentState += step;
        diff = currentState - target;
        if ((diff & 1) == 0) return step;
        return step + 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;

        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}
// } Driver Code Ends