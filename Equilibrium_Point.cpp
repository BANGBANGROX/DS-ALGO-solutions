// { Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(ll a[], int n) {
        // Your code here
        if (n == 1) return 1;

        ll sum = a[0];

        for (int i = n - 2; i >= 0; --i) {
            a[i] += a[i + 1];
        }


        for (int i = 1; i < n - 1; ++i) {
            if (a[i + 1] == sum) return i + 1;
            sum += (a[i + 1] - a[i]);
        }

        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long* a = new long long[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends