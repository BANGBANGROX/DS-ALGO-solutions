#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double val1 = (double)a.value / a.weight;
    double val2 = (double)b.value / b.weight;

    return val1 > val2;
}

double fractionalKnapsack(int W, Item a[], int n) {
    sort(a, a + n, compare);
    double ans = 0;

    for (int i = 0; i < n; ++i) {
        if (W >= a[i].weight) {
            ans += a[i].value;
            W -= a[i].weight;
        }
        else {
            ans += (double)a[i].value / (double)a[i].weight * (double)W;
            break;
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, w;
        cin >> n >> w;
        Item* a = new Item[n];
        for (int i = 0; i < n; ++i) cin >> a[i].value >> a[i].weight;

        cout << fractionalKnapsack(w, a, n) << endl;
    }

    return 0;
}