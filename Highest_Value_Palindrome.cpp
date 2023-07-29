#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    int mid = n / 2;
    vector<bool> visited(mid);

    for (int i = 0; i < mid; ++i) {
        visited[i] = (s[i] == s[n - i - 1]);
        if (!visited[i]) {
            if (k > 0) --k;
            else return "-1";
        }
        s[i] = max(s[i], s[n - i - 1]);
        s[n - i - 1] = s[i];
    }

    for (int i = 0; i < mid && k > 0; ++i) {
        if (s[i] != '9' && ((visited[i] && k > 1) || (!visited[i] && k > 0))) {
            s[i] = s[n - i - 1] = '9';
            k -= (visited[i] ? 2 : 1);
        }
    }

    if ((n & 1) > 0 && k > 0) s[mid] = '9';

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
