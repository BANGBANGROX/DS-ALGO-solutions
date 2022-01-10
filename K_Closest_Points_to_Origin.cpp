#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    double findDistance(int x, int y) {
        return sqrt(x * x + y * y);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue < pair<double, pair<int, int>>> pq;
        
        for (const vector<int>& point : points) {
            int x = point[0], y = point[1];
            double distance = findDistance(x, y);
            if (pq.size() < k) {
                pq.push({ distance,{x,y} });
            }
            else {
                pair<double, pair<int, int>> z = pq.top();
                if (z.first > distance) {
                    pq.pop();
                    pq.push({ distance,{x,y} });
                }
            }
        }

        while (!pq.empty()) {
            pair<double, pair<int, int>> z = pq.top();
            pq.pop();
            ans.push_back({ z.second.first,z.second.second });
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;
        vector<vector<int>> points(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = { x,y };
        }
        cin >> k;

        Solution obj;
        vector<vector<int>> ans = obj.kClosest(points, k);
        for (const vector<int>& x : points) {
            cout << x[0] << " " << x[1] << endl;
        }
        cout << endl;
    }

    return 0;
}
