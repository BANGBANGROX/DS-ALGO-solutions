#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> count;

        for (string &s : arr)
        {
            if (count.find(s) == count.end())
            {
                count[s] = 0;
            }
            ++count[s];
        }

        for (string &s : arr)
        {
            if (count[s] == 1)
            {
                --k;
                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases-- > 0)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (string &s : arr)
        {
            cin >> s;
        }
        int k;
        cin >> k;

        cout << (new Solution())->kthDistinct(arr, k);
    }

    return 0;
}