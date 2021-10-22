// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;
#define MAX 1000

int a[MAX][MAX];
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<int>> vec = uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++) {
            for (int x : vec[i]) {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this function*/

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
    //Your code here
    map<vector<int>, bool> m;
    vector<vector<int>> res;

    for (int i = 0; i < row; ++i) {
        vector<int> temp;
        for (int j = 0; j < col; ++j) {
            temp.push_back(M[i][j]);
        }
        if (m.find(temp) == m.end()) {
            res.push_back(temp);
            m[temp] = 1;
        }
    }

    return res;
}