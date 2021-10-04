#include<bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> s;
public:

    int currMin = INT_MAX;
    int getMin() {
        if (s.empty()) return -1;

        return currMin;
    }

    int pop() {
        if (s.empty()) return -1;

        int value = s.top();

        if (value > currMin) {
            s.pop();
            return value;
        }

        int newMin = 2 * currMin - value;
        s.pop();
        value = currMin;
        currMin = newMin;

        return value;

    }

    void push(int x) {

        if (x > currMin) {
            s.push(x);
            return;
        }

        s.push(2 * x - currMin);
        currMin = x;
    }
};

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while (q--) {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                cout << ob.pop() << " ";
            }
            else if (qt == 3)
            {
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}