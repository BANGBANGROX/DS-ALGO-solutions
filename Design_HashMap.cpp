#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    const int N = 1e6 + 5;
    int* hashMap;
    MyHashMap() {
        hashMap = new int[N];
        for (int i = 0; i < N; ++i) hashMap[i] = -1;
    }

    void put(int key, int value) {
        hashMap[key] = value;
    }

    int get(int key) {
        return hashMap[key];
    }

    void remove(int key) {
        hashMap[key] = -1;
    }
};

int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    cout << myHashMap.get(1) << endl;   // return 1, The map is now [[1,1], [2,2]]
    cout << myHashMap.get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    cout << myHashMap.get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    cout << myHashMap.get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
}