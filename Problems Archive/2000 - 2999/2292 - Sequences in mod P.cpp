#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
ll P;

ll power(ll x, ll n) {
    ll res = 1;
    for (; n; n >>= 1, x = (x * x) % P)
        if (n & 1) res = (res * x) % P;
    return res;
}

ll modInv(ll x) { return power(x, P - 2); }

ll discreteLog(ll a, ll b) {
    a %= P, b %= P; ll n = (ll)sqrt(P) + 1;

    map<ll, ll> vals;
    for (ll p = 1; p <= n; ++p)
        vals[power(a, p * n)] = p;

    for (ll q = 0; q <= n; ++q) {
        ll cur = (power(a, q) * b) % P;
        if (vals.count(cur)) { return vals[cur] * n - q; }
    }
    return -1;
}

ll getOrder(ll A) {
    ll res = P - 1;
    for (ll i = 1; i * i <= P; i++) {
        if ((P - 1) % i) { continue; }
        if (power(A, i) == 1) { return i; }
        if (power(A, (P - 1) / i) == 1) { res = (P - 1) / i; }
    }
    return res;
}

ll solve(ll A, ll B, ll S, ll G) {
    if (G == S) return 0;
    if (A == 0) return G == B ? 1 : -1;
    if (A == 1 && B == 0) return -1;
    if (A == 1) return ((G - S + P) * modInv(B)) % P;

    ll Y = (B * modInv(A - 1)) % P;
    G = (G + Y) % P; S = (S + Y) % P;
    if (G == 0 || S == 0) { return -1; }
    
    G = (G * modInv(S)) % P;
    ll res = discreteLog(A, G);
    if (res == -1) return -1;
    return res % getOrder(A);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        ll A, B, S, G; cin >> P >> A >> B >> S >> G;
        cout << solve(A, B, S, G) << '\n';
    }
}