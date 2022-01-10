// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    string one[20] = { "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ",
    "eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen " };
    string ten[10] = { "","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety " };
    const int crore = 1e7, lakh = 1e5, thousand = 1000, hundred = 100;


    string convertToWordsUtil(long n, string s) {
        string res("");

        if (n > 19) {
            res += ten[n / 10] + one[n % 10];
        }
        else {
            res += one[n];
        }

        if (n) res += s;

        return res;
    }

public:
    string convertToWords(long n) {
        // code here

        for (int i = 1; i <= 19; ++i) cout << one[i] << endl;

        string res("");

        res += convertToWordsUtil(n / crore, "crore ");

        res += convertToWordsUtil((n / lakh) % hundred, "lakh ");

        res += convertToWordsUtil((n / thousand) % hundred, "thousand ");

        res += convertToWordsUtil((n / hundred) % 10, "hundred ");

        if (n > 100 && n % 100 != 0) {
            res += "and ";
        }

        res += convertToWordsUtil(n % 100, "");

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends