#include<bits/stdc++.h>
using namespace std;

class CombinationIterator {
public:
    vector<string> words;
    int size, index;

    void generateWords(int len, int combinationLength, string& currWord, string& characters, int index) {
        if (len == combinationLength) {
            words.push_back(currWord);
            return;
        }

        if (index >= characters.size()) return;

        currWord += characters[index];
        generateWords(len + 1, combinationLength, currWord, characters, index + 1);

        currWord.pop_back();
        generateWords(len, combinationLength, currWord, characters, index + 1);
    }

    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();

        for (int i = 0; i <= n - combinationLength; ++i) {
            string currWord("");
            currWord += characters[i];
            generateWords(1, combinationLength, currWord, characters, i + 1);
        }

        size = words.size();
        index = 0;
    }

    string next() {
        return words[index++];
    }

    bool hasNext() {
        return index < size;
    }
};

int main() {
    CombinationIterator itr("abc", 2);

    cout << itr.next() << endl;   // return "ab"
    cout << itr.hasNext() << endl; // return True
    cout << itr.next() << endl;    // return "ac"
    cout << itr.hasNext() << endl; // return True
    cout << itr.next() << endl;    // return "bc"
    cout << itr.hasNext() << endl; // return False

    return 0;
}