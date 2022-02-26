// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string moveRobots(string s1, string s2) {
        // code here 
        int n = s1.size();

        if (s1.compare(s2) == 0) return "Yes";

        vector<int> aPosIn1;
        vector<int> aPosIn2;
        vector<int> bPosIn1;
        vector<int> bPosIn2;

        for (int i = 0; i < n; ++i) {
            if (s1[i] == 'A') aPosIn1.push_back(i);
            if (s2[i] == 'A') aPosIn2.push_back(i);
            if (s1[i] == 'B') bPosIn1.push_back(i);
            if (s2[i] == 'B') bPosIn2.push_back(i);
        }

        reverse(bPosIn1.begin(), bPosIn1.end());
        reverse(bPosIn2.begin(), bPosIn2.end());

        int ptr = 0;

        while (ptr < bPosIn1.size()) {
            int pos1 = bPosIn1[ptr];
            int pos2 = bPosIn2[ptr];
            if (pos1 == pos2) {
                ++ptr;
                continue;
            }
            if (pos2 < pos1 || s1[pos2] != '#') return "No";
            for (int i = pos1 + 1; i < pos2; ++i) {
                if (s1[i] != '#') return "No";
            }
            s1[pos1] = '#';
            s1[pos2] = 'B';
            ++ptr;
        }

        ptr = 0;

        while (ptr < aPosIn1.size()) {
            int pos1 = aPosIn1[ptr];
            int pos2 = aPosIn2[ptr];
            if (pos1 == pos2) {
                ++ptr;
                continue;
            }
            if (pos2 > pos1 || s1[pos2] != '#') return "No";
            for (int i = pos2 + 1; i < pos1; ++i) {
                if (s1[i] != '#') return "No";
            }
            s1[pos1] = '#';
            s1[pos2] = 'A';
            ++ptr;
        }

        return "Yes";
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends