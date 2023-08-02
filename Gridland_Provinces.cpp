#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

typedef long long int ll;

const int MAX_N = 10000;
const int MOD = 2147483607;
const int VAL_1 = 107;
const int VAL_2 = 101;
vector<ll> power1(MAX_N);
vector<ll> power2(MAX_N);
unordered_set<int> result;

void init() {
    power1[0] = power2[0] = 1;

    for (int i = 1; i < MAX_N; ++i) {
        power1[i] = (power1[i - 1] * VAL_1) % MOD;
        power2[i] = (power2[i - 1] * VAL_2) % MOD;
    }
}

void process(string& s1, string& s2, int ind, bool flag) {
    ll p1 = 0;
    ll p2 = 0;
    ll p3 = 0;
    ll p4 = 0;
    int m = (int)s1.size();

    for (int i = 0; i < ind; ++i) {
        p1 = (p1 + (s1[i] * power1[ind - i - 1]) % MOD) % MOD;
        p1 = (p1 + (s2[i] * power1[ind + i]) % MOD) % MOD;
        p3 = (p3 + (s1[i] * power2[ind - i - 1]) % MOD) % MOD;
        p3 = (p3 + (s2[i] * power2[ind + i]) % MOD) % MOD;
    }

    if (flag) {
        p1 = (p1 + (s2[ind] * power1[ind * 2]) % MOD) % MOD;
        p1 = (p1 + (s1[ind] * power1[ind * 2 + 1]) % MOD) % MOD;
        p3 = (p3 + (s2[ind] * power2[ind * 2]) % MOD) % MOD;
        p3 = (p3 + (s1[ind] * power2[ind * 2 + 1]) % MOD) % MOD;
        swap(s1, s2);
        ++ind;
    }

    for (int i = ind; i < m; ++i) {
        p2 = (p2 + (s1[i] * power1[m * 2 + ind - i - 1]) % MOD) % MOD;
        p2 = (p2 + (s2[i] * power1[ind + i]) % MOD) % MOD;
        p4 = (p4 + (s1[i] * power2[m * 2 + ind - i - 1]) % MOD) % MOD;
        p4 = (p4 + (s2[i] * power2[ind + i]) % MOD) % MOD;
    }

    result.insert((((p1 + p2) % MOD) * MOD + (p3 + p4) % MOD) % MOD);

    for (int i = ind; i < m - 1; i += 2) {
        p1 = (p1 + (s2[i] * power1[i * 2]) % MOD) % MOD;
        p1 = (p1 + (s1[i] * power1[i * 2 + 1]) % MOD) % MOD;
        p1 = (p1 + (s1[i + 1] * power1[i * 2 + 2]) % MOD) % MOD;
        p1 = (p1 + (s2[i + 1] * power1[i * 2 + 3]) % MOD) % MOD;
        p2 = (p2 + (s2[i] * (MOD - power1[i * 2])) % MOD) % MOD;
        p2 = (p2 + (s2[i + 1] * (MOD - power1[i * 2 + 1])) % MOD) % MOD;
        p2 = (p2 + (s1[i] * (MOD - power1[m * 2 - 1])) % MOD) % MOD;
        p2 = (p2 + (s1[i + 1] * (MOD - power1[m * 2 - 2])) % MOD) % MOD;
        p2 = (((p2 * VAL_1) % MOD) * VAL_1) % MOD;

        p3 = (p3 + (s2[i] * power2[i * 2]) % MOD) % MOD;
        p3 = (p3 + (s1[i] * power2[i * 2 + 1]) % MOD) % MOD;
        p3 = (p3 + (s1[i + 1] * power2[i * 2 + 2]) % MOD) % MOD;
        p3 = (p3 + (s2[i + 1] * power2[i * 2 + 3]) % MOD) % MOD;
        p4 = (p4 + (s2[i] * (MOD - power2[i * 2])) % MOD) % MOD;
        p4 = (p4 + (s2[i + 1] * (MOD - power2[i * 2 + 1])) % MOD) % MOD;
        p4 = (p4 + (s1[i] * (MOD - power2[m * 2 - 1])) % MOD) % MOD;
        p4 = (p4 + (s1[i + 1] * (MOD - power2[m * 2 - 2])) % MOD) % MOD;
        p4 = (((p4 * VAL_2) % MOD) * VAL_2) % MOD;

        result.insert((((p1 + p2) % MOD) * MOD + (p3 + p4) % MOD) % MOD);
    }
}

/*
 * Complete the 'gridlandProvinces' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int gridlandProvinces(string s1, string s2) {
    int m = (int)s1.size();
    result.clear();

    for (int i = 0; i < m; ++i) {
        process(s1, s2, i, false);
        process(s2, s1, i, false);
        process(s1, s2, i, true);
        process(s2, s1, i, true);
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < m; ++i) {
        process(s1, s2, i, false);
        process(s2, s1, i, false);
        process(s1, s2, i, true);
        process(s2, s1, i, true);
    }

    return (int)result.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string p_temp;
    getline(cin, p_temp);

    init();

    int p = stoi(ltrim(rtrim(p_temp)));

    for (int p_itr = 0; p_itr < p; p_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        int result = gridlandProvinces(s1, s2);

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
