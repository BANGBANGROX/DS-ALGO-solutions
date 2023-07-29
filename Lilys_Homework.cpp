#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


int calculateMinSwapsToSort(vector<vector<int>>& numsWithPos, int n) {
    int answer = 0;
    vector<bool> visited(n);

    for (int i = 0; i < n; ++i) {
        if (visited[i] || numsWithPos[i][1] == i) continue;
        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = numsWithPos[j][1];
            ++cycleSize;
        }
        if (cycleSize > 0) {
            answer += (cycleSize - 1);
        }
    }

    return answer;
}

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int>& nums) {
    int n = (int)nums.size();
    vector<vector<int>> numsWithPos(n);

    for (int i = 0; i < n; ++i) {
        numsWithPos[i] = { nums[i],i };
    }

    sort(numsWithPos.begin(), numsWithPos.end());

    int result1 = calculateMinSwapsToSort(numsWithPos, n);

    sort(numsWithPos.begin(), numsWithPos.end(), greater<vector<int>>());

    int result2 = calculateMinSwapsToSort(numsWithPos, n);

    return min(result1, result2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
