#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
    vector<bool> hash;
    const int MAX_SIZE = 1e6 + 5;

public:
    MyHashSet() {
        hash = vector<bool>(MAX_SIZE);
    }

    void add(int key) {
        hash[key] = true;
    }

    void remove(int key) {
        hash[key] = false;
    }

    bool contains(int key) {
        return hash[key];
    }
};


int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}