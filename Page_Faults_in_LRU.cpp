#include<bits/stdc++.h>
using namespace std;

int pageFaults(int n, int c, int pages[]) {
	int res = 0;
	vector<int> v;

	for (int i = 0; i < n; ++i) {
		auto it = find(v.begin(), v.end(), pages[i]);
		if (it == v.end()) {
			if (v.size() == c) {
				v.erase(v.begin());
			}
			v.push_back(pages[i]);
			++res;
		}
		else {
			v.erase(it);
			v.push_back(pages[i]);
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, c;
		cin >> n >> c;
		int* a = new int[n];

		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << pageFaults(n, c, a) << endl;
	}

	return 0;
}

//compute the function point value for the grade calculation of students.Assume that it is average complexity size project.The information domain value are as follows :
//No of inputs = 13; * 4(s) * 6(c)
//No of outputs = 4; * 5(s) * 7(c)
//No of inquires = 2; * 4(s) * 6(c)
//No of external files = 5; * 10(s) * 15(c)
//No of interfaces = 2; * 7(s) * 10(c)
//Total value of complexity adjustment attribute = 13;
//Calculate the function point matrix of average complexity size project
