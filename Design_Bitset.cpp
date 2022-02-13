#include<bits/stdc++.h>
using namespace std;

class Bitset {
    vector<int> bits;
    int ones;
    int zeroes;
    int size;
    bool flipBits;

    void setBit(int idx, int bit) {
        if (!flipBits) {
            if (bits[idx] == bit) return;
            if (bit == 1) {
                ++ones;
                --zeroes;
            }
            else {
                ++zeroes;
                --ones;
            }
            bits[idx] = bit;
            return;
        }

        if (bits[idx] == 1 - bit) return;
        
        if (bit == 1) {
            ++ones;
            --zeroes;
        }
        else {
            ++zeroes;
            --ones;
        }

        bits[idx] = 1 - bit;
    }

public:
    Bitset(int size) {
        bits = vector<int>(size);
        ones = 0;
        zeroes = size;
        this->size = size;
        flipBits = false;
    }

    void fix(int idx) {
        setBit(idx, 1);
    }

    void unfix(int idx) {
        setBit(idx, 0);
    }

    void flip() {
        flipBits = !flipBits;
        swap(ones, zeroes);
    }

    bool all() {
        return ones == size;
    }

    bool one() {
        return ones > 0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string bitSet("");

        for (int i = 0; i < size; ++i) {
            if (!flipBits) {
                bitSet += to_string(bits[i]);
            }
            else {
                bitSet += to_string(1 - bits[i]);
            }
        }

        return bitSet;
    }
};

int main() {
    Bitset bs(5); // bitset = "00000".
    bs.fix(3);     // the value at idx = 3 is updated to 1, so bitset = "00010".
    bs.fix(1);     // the value at idx = 1 is updated to 1, so bitset = "01010". 
    bs.flip();     // the value of each bit is flipped, so bitset = "10101". 
    cout << bs.all() << endl;      // return False, as not all values of the bitset are 1.
    bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "00101".
    bs.flip();     // the value of each bit is flipped, so bitset = "11010". 
    cout << bs.one() << endl;       // return True, as there is at least 1 index with value 1.
    bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "01010".
    cout << bs.count() << endl;     // return 2, as there are 2 bits with value 1.
    cout << bs.toString() << endl; // return "01010", which is the composition of bitset.

	return 0;
}