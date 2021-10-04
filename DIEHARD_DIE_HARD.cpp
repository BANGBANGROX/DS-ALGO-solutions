#include<bits/stdc++.h>
using namespace std;

int findMaxTimeAlive(int health, int armor) {
	int timeAlive = 0, location = 0;

	while (health > 0 && armor > 0) {
		if (location % 2 == 0) {
			++timeAlive;
			health += 3;
			armor += 2;
		}
		else {
			if ((health - 5) > 0 && (armor - 10) > 0) {
				++timeAlive;
				health -= 5;
				armor -= 10;
			}
			else if ((health - 20) > 0 && (armor + 5) > 0) {
				++timeAlive;
				health -= 20;
				armor += 5;
			}
			else {
				break;
			}
		}
		++location;
	}

	return timeAlive;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int health, armor;
		cin >> health >> armor;

		cout << findMaxTimeAlive(health, armor) << endl;
	}

	return 0;
}
