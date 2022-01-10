#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans, aux;
        unordered_map<int, int> freq;

        for (int x : arr1) {
            ++freq[x];
        }

        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                --freq[x];
            }
        }

        for (int x : arr1) {
            while (freq[x] > 0) {
                aux.push_back(x);
                --freq[x];
            }
        }

        sort(aux.begin(), aux.end());

        for (int x : aux) ans.push_back(x);

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m;
        vector<int> arr1(m);
        for (int& x : arr1) cin >> x;
        cin >> n;
        vector<int> arr2(n);
        for (int& x : arr2) cin >> x;

        Solution obj;
        vector<int> ans = obj.relativeSortArray(arr1, arr2);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}