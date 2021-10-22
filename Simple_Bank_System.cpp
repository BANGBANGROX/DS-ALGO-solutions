#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Bank {
public:

    vector<ll> balance;

    Bank(vector<ll>& balance) {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, ll money) {
        --account1;
        --account2;

        if (account1 >= balance.size() || account2 >= balance.size() || balance[account1] < money) return false;

        balance[account1] -= money;
        balance[account2] += money;

        return true;
    }

    bool deposit(int account, ll money) {
        --account;

        if (account >= balance.size()) return false;

        balance[account] += money;

        return true;
    }

    bool withdraw(int account, ll money) {
        --account;

        if (account >= balance.size() || balance[account] < money) return false;

        balance[account] -= money;

        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> balance(n);

    for (ll& x : balance) cin >> x;

    Bank bank(balance);

    return 0;
}
