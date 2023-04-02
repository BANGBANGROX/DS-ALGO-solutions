//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
public:
    int getMinimumDays(int n, string s, vector<int> &p) {
        // code here
        int match = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ++match;
            }
        }

        if (match == 0) return 0;

        for (int d = 0; d < n; ++d) {
            int i = p[d];
            if (i + 1 < n && s[i] == s[i + 1]) --match;
            if (i > 0 && s[i] == s[i - 1]) --match;
            if (match <= 0) return d + 1;
            s[i] = '?';
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends