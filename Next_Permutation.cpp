#include<bits/stdc++.h>
using namespace std;

void reverse(int l, int r, vector<int>& a) {
    while (l < r) {
        swap(a[l], a[r]);
        ++l;
        --r;
    }
}

int bsearch(int l, int r, vector<int>& a, int key) {
    int index = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= key) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
            if (index == -1 || a[index] >= a[mid]) {
                index = mid;
            }
        }
    }

    return index;
}

vector<int> nextPermutation(int n, vector<int> arr) {
    int i = n - 2;

    for (; i > -1 && arr[i] >= arr[i + 1]; --i);

    if (i < 0) { // not possible so return reverse 
        reverse(0, n - 1, arr);
        return arr;
    }

    int index = bsearch(i + 1, n - 1, arr, arr[i]);
    swap(arr[i], arr[index]);
    reverse(i + 1, n - 1, arr);

    return arr;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> res = nextPermutation(n, a);

        for (int x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}