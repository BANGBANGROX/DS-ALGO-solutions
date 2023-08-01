// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

int getIndex(char ch) {
    if (ch == 'A') return 0;

    if (ch == 'C') return 1;

    if (ch == 'G') return 2;

    return 3;
}

bool isSteady(vector<int>& count, int limit) {
    return count[0] == limit && count[1] == limit &&
        count[2] == limit && count[3] == limit;
}

bool canBeSteady(vector<int>& count, int limit) {
    return count[0] <= limit && count[1] <= limit &&
        count[2] <= limit && count[3] <= limit;
}

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene) {
    const int n = (int)gene.size();
    int l = 0;
    int answer = n;
    int limit = n / 4;
    vector<int> count(4);

    for (char ch : gene) {
        ++count[getIndex(ch)];
    }

    if (isSteady(count, limit)) {
        return 0;
    }

    if (canBeSteady(count, limit)) {
        return n;
    }

    for (int r = 0; r < n; ++r) {
        --count[getIndex(gene[r])];
        while (canBeSteady(count, limit)) {
            answer = min(answer, r - l + 1);
            ++count[getIndex(gene[l])];
            ++l;
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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
