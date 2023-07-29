//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;

    const int MOD = (int) 1e9 + 7;
    int c;
    int d;

    bool check(ll num) {
        while (num > 0) {
            ll dig = num % 10;
            if (dig != c && dig != d) return false;
            num /= 10;
        }

        return true;
    }

    ll computeInverse(ll num) {
        ll result = 1;
        ll power = MOD - 2;

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

  public:
    int bestNumbers(int n, int a, int b, int c, int d) {
        // code here
        ll answer = 0;
        this->c = c;
        this->d = d;
        vector<ll> factorial(n + 1);
        vector<ll> inverseFactorial(n + 1);

        factorial[0] = inverseFactorial[0] = 1;

        for (int i = 1; i <= n; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            inverseFactorial[i] = computeInverse(factorial[i]);
        }

        for (int i = 0; i <= n; ++i) {
            ll num = (ll) i * a + ((ll)n - i) * b;
            if (check(num)) {
                ll nci = (((factorial[n] * inverseFactorial[n - i]) % MOD) *
                        inverseFactorial[i]) % MOD;
                answer = (answer + nci) % MOD;
            }
        }

        return (int) answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends