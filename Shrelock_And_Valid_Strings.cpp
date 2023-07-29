#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> count(26);
    string result("YES");
    bool flag = false;
    int minValue = INT_MAX;

    for (char ch : s) {
        ++count[ch - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            minValue = min(minValue, count[i]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            if (count[i] - minValue > 1 || (count[i] - minValue == 1 && flag)) {
                result = "NO";
                break;
            }
            if (count[i] - minValue == 1) flag = true;
        }
    }

    if (minValue == 1 && result.compare("NO") == 0) {
        int last = -1;
        bool possible = true;
        int oneCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 1) {
                if (last == -1) last = count[i];
                else if (count[i] != last) {
                    possible = false;
                    break;
                }
            }
            else if (count[i] == 1) ++oneCount;
        }
        if (possible && oneCount == 1) result = "YES";
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
