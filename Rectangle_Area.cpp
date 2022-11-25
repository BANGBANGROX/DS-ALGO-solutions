#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, 
		int by1, int bx2, int by2) {
		int aArea = (ay2 - ay1) * (ax2 - ax1);
		int bArea = (by2 - by1) * (bx2 - bx1);
		int xOverlap = min(ax2, bx2) - max(ax1, bx1);
		int yOverlap = min(ay2, by2) - max(ay1, by1);
		
		return aArea + bArea - (xOverlap > 0 && 
			yOverlap > 0 ? xOverlap * yOverlap : 0);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
		cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

		Solution solution;
		cout << solution.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
	}

	return 0;
}