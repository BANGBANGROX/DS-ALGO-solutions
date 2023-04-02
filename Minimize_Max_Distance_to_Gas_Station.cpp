//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool check(vector<int>&stations, int k, double distance) {
        int count = 0;
        int n = (int) stations.size();

        for (int i = 1; i < n; ++i) {
            int gap = stations[i] - stations[i - 1];
            count += (int)(gap / distance);
            if (count > k) return false;
        }

        return true;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k){
      // Code here
      int n = (int) stations.size();
      double l = 0;
      double r = stations[n - 1] - stations[0];
      double ans = -1;
      const double DIFF = 1e-6;

      while (r - l >= DIFF) {
          double mid = (l + r) / 2;
          if (check(stations, k, mid)) {
              ans = mid;
              r = mid;
          }
          else l = mid;
      }

      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends