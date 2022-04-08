#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Encrypter {
    vector<int> keys;
    unordered_set<string> dictionary;
    unordered_map<string, int> encryptedDictionary;
    vector<string> values;
    
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = vector<int>(26, -1);
        this->values = values;
        this->dictionary = unordered_set<string>(dictionary.begin(), dictionary.end());

        for (int i = 0; i < keys.size(); ++i) {
            this->keys[keys[i] - 'a'] = i;
        }

        for (string& s : dictionary) {
            ++encryptedDictionary[encrypt(s)];
        }
    }

    string encrypt(string word1) {
        string ans("");

        for (char c : word1) {
            if (keys[c - 'a'] == -1) return "";
            ans += values[keys[c - 'a']];
        }

        return ans;
    }

    int decrypt(string word2) {
        if (encryptedDictionary.find(word2) == encryptedDictionary.end()) return 0;

        return encryptedDictionary[word2];
    }
};

int main() {
    vector<char> keys = { 'a', 'b', 'c', 'd' };
    vector<string> values = { "ei", "zf", "ei", "am" };
    vector<string> dictionary = { "abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad" };

    Encrypter encrypter(keys, values, dictionary);

    cout << encrypter.encrypt("abcd") << endl; // return "eizfeiam". 
                               // 'a' maps to "ei", 'b' maps to "zf", 'c' maps to "ei", and 'd' maps to "am".
    cout << encrypter.decrypt("eizfeiam") << endl; // return 2. 
    // "ei" can map to 'a' or 'c', "zf" maps to 'b', and "am" maps to 'd'. 
    // Thus, the possible strings after decryption are "abad", "cbad", "abcd", and "cbcd". 
    // 2 of those strings, "abad" and "abcd", appear in dictionary, so the answer is 2.

    return 0;
}