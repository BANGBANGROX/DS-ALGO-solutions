#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


typedef long long int ll;

vector<ll> factorial;
vector<ll> inverseFactorial;
vector<vector<int>> characterPrefix;
const int MOD = (int)1e9 + 7;


ll modularInverse(ll num) {
    int power = MOD - 2;
    ll result = 1;
    
    while (power > 0) {
        if ((power & 1) > 0) {
            result = (result * num) % MOD;
            --power;
        }
        num = (num * num) % MOD;
        power >>= 1;
    }

    return result;
}

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

void initialize(string s) {
    // This function is called once before all queries.
    int n = (int)s.size();
    factorial = vector<ll>(n + 1);
    inverseFactorial = vector<ll>(n + 1);
    characterPrefix = vector<vector<int>>(n + 1, vector<int>(26));

    factorial[0] = inverseFactorial[0] = 1;

    for (int i = 1; i <= n; ++i) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
        inverseFactorial[i] = modularInverse(factorial[i]);
        for (int j = 0; j < 26; ++j) {
            characterPrefix[i][j] += characterPrefix[i - 1][j];
        }
        ++characterPrefix[i][s[i - 1] - 'a'];
    }
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    ll answer = 1;
    int oddCount = 0;
    int total = 0;

    for (int i = 0; i < 26; ++i) {
        int characterCount = characterPrefix[r][i] - characterPrefix[l - 1][i];
        if ((characterCount & 1) > 0) {
            ++oddCount;
        }
        int val = characterCount / 2;
        answer = (answer * inverseFactorial[val]) % MOD;
        total += val;
    }

    answer = (answer * factorial[total]) % MOD;

    if (oddCount > 0) {
        answer = (answer * oddCount) % MOD;
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

        fout << result << "\n";
    }

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
