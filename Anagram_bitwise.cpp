#include<bits/stdc++.h>
using namespace std;

// Bitwise xor use karenge idhar
// x ^ y = 0 iff x = 1 and y = 1 or x = 0 and y = 0 mane x ^ y = 0 iff x = y
// Issi property ka use karenge
// s1 = abcd s2 = dbca xor kardenge dono ka toh a ^ d ^ b ^ b ^ c ^ c ^ d ^ a mane (a ^ a ^ b ^ b ^ c ^ c ^ d ^ d) = 0
// 0 toh anagram varna nahi

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int res = 0; // xor store karenge isme
	int n = s1.size(), m = s2.size();

	if (m != n) { // size hi barabar nahi hain anagram kaha se hogi
		cout << "Not anagrams";
		return 0;
	}

	for (int i = 0; i < n; ++i) { // size same ho toh xor karte jao 
		res = res ^ s1[i] ^ s2[i];
	}

	if (res == 0) {
		cout << "Anagrams";
	}
	else {
		cout << "Not anagrams";
	}

	return 0;
}
