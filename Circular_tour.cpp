#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n) {
    int start = 0, end = 1;
    int currentPetrol = p[start].petrol - p[start].distance;

    while (start != end && currentPetrol < 0) {
        while (currentPetrol < 0 || end != start) {
            currentPetrol -= (p[start].petrol - p[start].distance);
            start = (start + 1) % n;
            if (start == 0) return -1;
        }
        currentPetrol += (p[end].petrol - p[end].distance);
        end = (end + 1) % n;
    }

    return start;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        petrolPump* p = new petrolPump[n];

        for (int i = 0; i < n; ++i) cin >> p[i].petrol;
        for (int i = 0; i < n; ++i) cin >> p[i].distance;

        cout << tour(p, n) << endl;
    }

    return 0;
}
