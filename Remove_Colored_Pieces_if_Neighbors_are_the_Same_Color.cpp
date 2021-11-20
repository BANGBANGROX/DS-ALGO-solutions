#include<bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors) {
	int aliceMoves = 0, bobMoves = 0, n = colors.size();

	for (int i = 0; i < n; ++i) {
		if (colors[i] == 'A') {
			int cnt = 0;
			while (i < n && colors[i] == 'A') {
				++i;
				++cnt;
			}
			--i;
			if (cnt > 2) aliceMoves += (cnt - 2);
		}
		else {
			int cnt = 0;
			while (i < n && colors[i] == 'B') {
				++i;
				++cnt;
			}
			--i;
			if (cnt > 2) bobMoves += (cnt - 2);
		}
	}

	return aliceMoves > bobMoves;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string colors;
		cin >> colors;

		if (winnerOfGame(colors)) cout << "Alice wins\n";
		else cout << "Bob wins\n";
	}

	return 0;
}
