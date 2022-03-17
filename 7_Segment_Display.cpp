// https://practice.geeksforgeeks.org/problems/7-segment-display0752/1


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public :
    string sevenSegments(string s, int n) {
        // code here
        int segmentSum = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '0' || c == '6') segmentSum += 6;
            if (c == '1') segmentSum += 2;
            if (c == '2' || c == '3' || c == '5' || c == '9') segmentSum += 5;
            if (c == '4') segmentSum += 4;
            if (c == '7') segmentSum += 3;
            if (c == '8') segmentSum += 7;
        }

        segmentSum -= (2 * n); // Fill all the segments with 1

        vector<int> segments(n, 1);
        int i = 0;

        while (segmentSum - 4 >= 0 && i < n) {
            segments[i] = 0;
            ++i;
            segmentSum -= 4;
        }

        i = n - 1;

        while (segmentSum > 0 && i >= 0) {
            if (segmentSum - 5 >= 0) {
                segments[i] = 8;
                segmentSum -= 5;
                --i;
            }
            else if (segmentSum - 4 >= 0) {
                segments[i] = 6;
                segmentSum -= 4;
                --i;
            }
            else if (segmentSum - 3 >= 0) {
                segments[i] = 2;
                segmentSum -= 3;
                --i;
            }
            else if (segmentSum - 2 >= 0) {
                segments[i] = 4;
                segmentSum -= 2;
                --i;
            }
            else if (segmentSum - 1 >= 0) {
                segments[i] = 7;
                segmentSum -= 1;
                --i;
            }
        }

        string ans("");

        for (int& seg : segments) ans += to_string(seg);

        return ans;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.sevenSegments(S, N) << endl;
    }
    return 0;
}  // } Driver Code Ends