// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution {
public:
    int maxSubarrayXOR(int arr[], int n) {
        //Your code here
        int ans = 0;
        int index = 0;

        for (int bit = 31; bit >= 0; --bit) {
            int maxIndex = -1;
            for (int i = index; i < n; ++i) {
                int res = (arr[i] & (1 << bit));
                if (res > 0 && (maxIndex == -1 || arr[maxIndex] < arr[i])) {
                    maxIndex = i;
                }
            }
            if (maxIndex == -1) continue;
            swap(arr[maxIndex], arr[index]);
            maxIndex = index;
            for (int i = 0; i < n; ++i) {
                int res = (arr[i] & (1 << bit));
                if (res > 0 && i != maxIndex) {
                    arr[i] = arr[i] ^ arr[maxIndex];
                }
            }
            ++index;
        }

        for (int i = 0; i < n; ++i) {
            ans = ans ^ arr[i];
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t, n, a[100004], k;
    scanf_s("%d", &t);
    while (t--)
    {
        //cin>>n;
        scanf_s("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf_s("%d", &a[i]);
        }
        Solution obj;
        printf("%d\n", obj.maxSubarrayXOR(a, n));
        // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends