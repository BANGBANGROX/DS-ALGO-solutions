// https://leetcode.com/problems/maximum-frequency-stack/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class FreqStack {
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> st;
    int maxCount;

public:
    FreqStack() {
        maxCount = 0;
    }

    void push(int val) {
        ++count[val];
        st[count[val]].push(val);
        maxCount = max(maxCount, count[val]);
    }

    int pop() {
        int ans = st[maxCount].top();
        st[maxCount].pop();
        --count[ans];
        if (st[maxCount].empty()) --maxCount;

        return ans;
    }
};

int main() {
    FreqStack freqStack;

    freqStack.push(5); // The stack is [5]
    freqStack.push(7); // The stack is [5,7]
    freqStack.push(5); // The stack is [5,7,5]
    freqStack.push(7); // The stack is [5,7,5,7]
    freqStack.push(4); // The stack is [5,7,5,7,4]
    freqStack.push(5); // The stack is [5,7,5,7,4,5]
    cout << freqStack.pop() << endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout << freqStack.pop() << endl;   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout << freqStack.pop() << endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout << freqStack.pop() << endl;   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. 

	return 0;
}