// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) {
        // Your code here
        int left = 0, right = n - 1, res = 0; 

        while (right >= left) {
            if (a[right] >= a[left]) {
                res = max(res, right - left);
                ++left;
                right = n - 1;
            }
            else --right;
        }

        return res;
    }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    //testcases
    cin >> T;
    while (T--) {
        int num;
        //size of array
        cin >> num;
        int* arr = new int[num];

        //inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        //calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;

    }
    return 0;
}   // } Driver Code Ends