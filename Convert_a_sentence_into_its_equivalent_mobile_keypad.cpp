// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << printSequence(s) << endl;
    }
    return 0;
}
// } Driver Code Ends


string printSequence(string s) {
    //code here.
    string ans("");

    for (char ch : s) {
        if (ch == ' ') {
            ans += '0';
        }
        if (ch == 'A' || ch == 'B' || ch == 'C') {
            if (ch == 'A') ans += "2";
            if (ch == 'B') ans += "22";
            if (ch == 'C') ans += "222";
        }
        if (ch == 'D' || ch == 'E' || ch == 'F') {
            if (ch == 'D') ans += "3";
            if (ch == 'E') ans += "33";
            if (ch == 'F') ans += "333";
        }
        if (ch == 'G' || ch == 'H' || ch == 'I') {
            if (ch == 'G') ans += "4";
            if (ch == 'H') ans += "44";
            if (ch == 'I') ans += "444";
        }
        if (ch == 'J' || ch == 'K' || ch == 'L') {
            if (ch == 'J') ans += "5";
            if (ch == 'K') ans += "55";
            if (ch == 'L') ans += "555";
        }
        if (ch == 'M' || ch == 'N' || ch == 'O') {
            if (ch == 'M') ans += "6";
            if (ch == 'N') ans += "66";
            if (ch == 'O') ans += "666";
        }
        if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S') {
            if (ch == 'P') ans += "7";
            if (ch == 'Q') ans += "77";
            if (ch == 'R') ans += "777";
            if (ch == 'S') ans += "7777";
        }
        if (ch == 'T' || ch == 'U' || ch == 'V') {
            if (ch == 'T') ans += "8";
            if (ch == 'U') ans += "88";
            if (ch == 'V') ans += "888";
        }
        if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') {
            if (ch == 'W') ans += "9";
            if (ch == 'X') ans += "99";
            if (ch == 'Y') ans += "999";
            if (ch == 'Z') ans += "9999";
        }
    }

    return ans;
}