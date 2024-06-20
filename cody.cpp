#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int P = 29, N = 1e5 + 6, MOD = 1e9 + 7;
int inv[N],fact[N];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return 1ll * a * b % MOD;
}

ll sub(ll a, ll b) {
    return ((a - b) % MOD + MOD) % MOD;
}
ll power(ll b, ll p) {
    int ans = 1;
    for (; p; p /= 2) {
        if (p & 1)
            ans = mul(ans, b);
        b = mul(b, b);
    }
    return ans%MOD;
}

void prepare() {
   fact[1] = inv[1] = 1;
    for (int i = 2;i < N;i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = power(fact[i], MOD - 2);
    }
}


void test_case()
{
    


}
int main()
{
    fast
    int t=1;
    prepare();
//freopen("inc.in", "r", stdin);
    cin>>t;

    while(t--)
    {
        test_case();
    }


}
