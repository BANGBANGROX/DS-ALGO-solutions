//{ Driver Code Starts
// C++ program to count 2s from 0 to n
#include <bits/stdc++.h>
using namespace std;

/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d);
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number);

// Driver Coden
int main()
{
    long long int n;
    long long int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << numberOf2sinRange(n) << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long int ll;

ll numberOfTwos(int n) {
    int ans = 0;

    while (n > 0) {
        if (n % 10 == 2) ++ans;
        n /= 10;
    }

    return ans;
}

/* Counts the number of '2' digits between 0 and n */
ll numberOf2sinRange(ll n) {
    // Your code goes here
    if (n < 2) return 0;

    return numberOfTwos(n) + numberOf2sinRange(n - 1);
}