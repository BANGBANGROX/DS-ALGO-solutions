// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
	double getY(double x, vector<int> line) {
		return (double)(-1 * line[2] - line[0] * x) / line[1];
	}

	double getDistance(vector<pair<int, int>>& points, double x1, double y1) {
		double res = 0;

		for (pair<int, int>& point : points) {
			int x2 = point.first;
			int y2 = point.second;
			res += (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		}

		return res;
	}

public:
	double findOptimumCost(tuple<int, int, int>l, vector<pair<int, int>>points, int n) {
		//Write your code here
		vector<int> line(3);
		double ans = INT_MAX;

		line[0] = get<0>(l);
		line[1] = get<1>(l);
		line[2] = get<2>(l);

		if (line[1] == 0) return (double)1 / 0;

		double low = -1000;
		double high = 1000;

		while ((high - low) >= 0.0001) {
			double midX = (low + high) / 2;
			double midY = getY(midX, line);
			double distance = getDistance(points, midX, midY);
			ans = min(ans, distance);
			double newMidX = midX + 0.001;
			double newMidY = getY(newMidX, line);
			double newDistance = getDistance(points, newMidX, newMidY);
			if (newDistance > distance) high = midX;
			else low = midX;
		}

		return ans;
	}
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		tuple<int, int, int>line;
		int a, b, c;
		cin >> a >> b >> c;
		line = make_tuple(a, b, c);
		int n;
		cin >> n;
		vector<pair<int, int>>points;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			points.push_back({ x, y });
		}

		Solution ob;
		double ans = ob.findOptimumCost(line, points, n);

		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
// } Driver Code Ends