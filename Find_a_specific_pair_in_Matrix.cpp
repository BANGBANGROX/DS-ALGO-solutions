#include<bits/stdc++.h>
using namespace std;

pair<int, pair<pair<int, int>, pair<int, int>>> findPair(vector<vector<int>>& m, int n) {
	int maxValue = INT_MIN, x1 = n - 1, y1 = n - 1, x2 = n - 1, y2 = n - 1;

	vector<vector<int>> aux(n, vector<int>(n));
	vector<vector<pair<int, int>>> index(n, vector<pair<int, int>>(n));

	aux[n - 1][n - 1] = m[n - 1][n - 1]; // aux[i][j] mane max(m[i][j], m[i+1][j], ... , m[n-1][n-1])
	index[n - 1][n - 1] = { n - 1,n - 1 };

	// Sabse pehle last coloumn ko banate hain
	for (int i = n - 2; i > -1; --i) {   // ((0,n-1), (1,n-1), (2,n-1), (3,n-1), ... (n-1, n-1)) aisa hoga last coloumn
										 // toh ulta chalte hain ab jo (3,n-1) ke liye hain wo (3,n-1), (4,n-1), ... ,(n-1,n-1)
										 // sabka max hoga ab (2,n-1) ka nikalna ho toh wo m[2][n-1] aur aux[3][n-1] ka max 
										 // hoga aise hi generalise kar liya hu
		if (m[i][n - 1] > aux[i + 1][n - 1]) {
			aux[i][n - 1] = m[i][n - 1];
			index[i][n - 1] = { i,n - 1 };
		}
		else {
			aux[i][n - 1] = aux[i + 1][n - 1];
			index[i][n - 1] = index[i + 1][n - 1];
		}
	}

	for (int i = n - 2; i > -1; --i) { // Same chiz for last row
		if (m[n - 1][i] > aux[n - 1][i + 1]) {
			aux[n - 1][i] = m[n - 1][i];
			index[n - 1][i] = { n - 1,i };
		}
		else {
			aux[n - 1][i] = aux[n - 1][i + 1];
			index[n - 1][i] = index[n - 1][i + 1];
		}
	}

	for (int i = n - 2; i > -1; --i) { // Ab aate hain question pe, ab ek (i,j) ke liye answer nikalna ho toh wo kya hoga
									   // max of (i+1,j+1)...(n-1,n-1) - m[i][j] yahi hoga max apan store kar hi chuke hain 
									   // Issi ka overall max nikalna hain wo final answer hoga

		for (int j = n - 2; j > -1; --j) {
			if (aux[i + 1][j + 1] - m[i][j] > maxValue) {
				maxValue = aux[i + 1][j + 1] - m[i][j];
				x1 = i, y1 = j, x2 = index[i + 1][j + 1].first, y2 = index[i + 1][j + 1].second;
			}
			if (aux[i + 1][j] > aux[i][j + 1]) {
				aux[i][j] = aux[i + 1][j];
				index[i][j] = index[i + 1][j];
			}                                              // Baki aux ko banane ke liye apan ko kya karna hoga
														   // apne paas (i+1,j) ka answer hain aur (i,j+1) tak ka bhi answer 
														   // hain toh aux[i][j] kya hoga, in dono ka hi max hoga na bas yahi
														   // karte jana hain
			else {
				aux[i][j] = aux[i][j + 1];
				index[i][j] = index[i][j + 1];
			}

		}
	}

	return { maxValue,{{x1,y1},{x2,y2}} };
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> m(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> m[i][j];
			}
		}

		auto ans = findPair(m, n);

		cout << ans.first << endl << ans.second.first.first << " " << ans.second.first.second << endl
			<< ans.second.second.first << " " << ans.second.second.second << endl;
	}

	return 0;
}