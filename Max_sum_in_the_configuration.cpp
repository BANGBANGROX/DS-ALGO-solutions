//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int* A = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int nums[], int n) {
    //Your code here
    int currentSum = 0;
    int initialResult = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        initialResult += i * nums[i];
    }

    int ans = initialResult;

    for (int i = 0; i < n; ++i) {
        initialResult = (initialResult - (currentSum - nums[i]) + nums[i] * (n - 1));
        ans = max(ans, initialResult);
    }

    return ans;
}