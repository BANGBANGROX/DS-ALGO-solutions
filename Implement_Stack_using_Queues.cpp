#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {

    }

    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            return;
        }

        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;

        int ans = q1.front();
        q1.pop();

        return ans;
    }

    int top() {
        return q1.empty() ? -1 : q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // return 2
    cout << myStack.pop() << endl; // return 2
    cout << myStack.empty() << endl; // return False

	return 0;
}