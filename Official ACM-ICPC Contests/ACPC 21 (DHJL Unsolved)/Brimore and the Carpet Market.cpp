#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    freopen("brimore.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; map<ll, ll> m;
    while (n--) { int x; cin >> x; m[x]++; }

    ll sum = 0; for (auto& x : m)
        sum += ((x.second - 1) * x.second) >> 1;
    
    ll res = 0; for (auto& x : m)
        res += (sum - x.second) * x.second;
    
    cout << (res >> 1) << '\n';
}
