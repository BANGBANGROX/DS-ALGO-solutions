#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void printPath(map<pii, pii>& mp, pii u) {
	if (u == make_pair(0, 0)) {
		cout << 0 << " " << 0 << endl;
		return;
	}

	printPath(mp, mp[u]);

	cout << u.first << " " << u.second << endl;
}

void bfs(int a, int b, int d) {
	map<pii, pii> mp;
	map<pii, bool> m;
	queue<pii> q;

	bool isSolvable = false;

	q.push({ 0,0 });

	while (!q.empty()) {
		pii top = q.front();
		q.pop();
		if (m[top] == 1) continue;
		m[top] = 1;

		if (top.first > a || top.first < 0 || top.second > b || top.second < 0) continue; // Not possible cases

		if (top.first == d || top.second == d) { // Target reached
			isSolvable = true;
			printPath(mp, top);
			if (top.first == d) {
				if (top.second != 0) {
					cout << top.first << " " << 0 << endl;
				}
			}
			else {
				if (top.first != 0) {
					cout << 0 << " " << top.second << endl;
				}
			}
			return;
		}

		if (m[{top.first, b}] != 1) { // Fill jug b
			q.push({ top.first,b });
			mp[{top.first, b}] = top;
		}
		if (m[{a, top.second}] != 1) { // Fill jug a
			q.push({ a,top.second });
			mp[{a, top.second}] = top;
		}

		int diff = b - top.second; // Try to fill jug b using jug a
		if (top.first >= diff) { // Possible
			int c = top.first - diff;
			if (m[{c, b}] != 1) {
				q.push({ c,b });
				mp[{c, b}] = top;
			}
		}
		else { // Not possible then 
			int c = top.first + top.second;
			if (m[{0, c}] != 1) {
				q.push({ 0,c });
				mp[{0, c}] = top;
			}
		}

		diff = a - top.first; // Try to fill jug a using jug b
		if (top.second >= diff) {
			int c = top.second - diff;
			if (m[{a, c}] != 1) {
				q.push({ a,c });
				mp[{a, c}] = top;
			}
		}
		else {
			int c = top.first + top.second;
			if (m[{c, 0}] != 1) {
				q.push({ c,0 });
				mp[{c, 0}] = top;
			}
		}

		if (m[{top.first, 0}] != 1) { // Empty jug b
			q.push({ top.first,0 });
			mp[{top.first, 0}] = top;
		}

		if (m[{0, top.second}] != 1) { // Empty jug a
			q.push({ 0,top.second });
			mp[{0, top.second}] = top;
		}
	}

	if (!isSolvable) cout << "Unable to find a path!!!" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, d;
		cin >> a >> b >> d;

		bfs(a, b, d);
	}

	return 0;
}