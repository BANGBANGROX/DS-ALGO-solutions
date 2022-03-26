// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int* b;
        b = greaterElement(arr, n);
        for (int i = 0; i < n; i++) {
            if (b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout << endl;

    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n) {
    // Complete the function
    set<int> s(arr, arr + n);
    int* ans = new int[n];

    for (int i = 0; i < n; ++i) {
        auto it = s.upper_bound(arr[i]);
        if (it == s.end()) ans[i] = -10000000;
        else ans[i] = *it;
    }
    
    return ans;
}
