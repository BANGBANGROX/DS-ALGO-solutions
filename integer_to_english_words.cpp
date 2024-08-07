#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, string> numToString;
    vector<pair<int, string>> placeholders;

    void populateNumToString()
    {
        numToString[0] = "Zero";
        numToString[1] = "One";
        numToString[2] = "Two";
        numToString[3] = "Three";
        numToString[4] = "Four";
        numToString[5] = "Five";
        numToString[6] = "Six";
        numToString[7] = "Seven";
        numToString[8] = "Eight";
        numToString[9] = "Nine";
        numToString[10] = "Ten";
        numToString[11] = "Eleven";
        numToString[12] = "Twelve";
        numToString[13] = "Thirteen";
        numToString[14] = "Fourteen";
        numToString[15] = "Fifteen";
        numToString[16] = "Sixteen";
        numToString[17] = "Seventeen";
        numToString[18] = "Eighteen";
        numToString[19] = "Nineteen";
        numToString[20] = "Twenty";
        numToString[30] = "Thirty";
        numToString[40] = "Forty";
        numToString[50] = "Fifty";
        numToString[60] = "Sixty";
        numToString[70] = "Seventy";
        numToString[80] = "Eighty";
        numToString[90] = "Ninety";
        numToString[100] = "Hundred";
    }

    void populatePlaceholders()
    {
        placeholders.push_back({1000000000, "Billion"});
        placeholders.push_back({1000000, "Million"});
        placeholders.push_back({1000, "Thousand"});
    }

    vector<string> convert(int num)
    {
        vector<string> result;

        if (num >= 100)
        {
            result.push_back(numToString[num / 100]);
            result.push_back(numToString[100]);
            num %= 100;
        }

        if (num >= 20)
        {
            result.push_back(numToString[num / 10 * 10]);
            num %= 10;
        }

        if (num > 0)
        {
            result.push_back(numToString[num]);
        }

        return result;
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }

        vector<string> ansVector;
        string answer("");

        populateNumToString();
        populatePlaceholders();

        for (pair<int, string> &placeholder : placeholders)
        {
            if (num >= placeholder.first)
            {
                int val = num / placeholder.first;
                num %= placeholder.first;
                vector<string> convertedNum = convert(val);
                for (string &s : convertedNum)
                {
                    ansVector.push_back(s);
                }
                ansVector.push_back(placeholder.second);
            }
        }

        if (num > 0)
        {
            vector<string> convertedNum = convert(num);
            for (string &s : convertedNum)
            {
                ansVector.push_back(s);
            }
        }

        int len = ansVector.size();

        for (int i = 0; i < len; ++i)
        {
            answer += ansVector[i];
            if (i != len - 1)
            {
                answer += " ";
            }
        }

        return answer;
    }
};

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases-- > 0)
    {
        int num;
        cin >> num;
        cout << (new Solution())->numberToWords(num) << endl;
    }

    return 0;
}