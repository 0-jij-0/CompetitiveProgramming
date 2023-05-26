#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> pref;

ll power(ll x, ll n){
    ll res = 1;
    for (; n; n >>= 1, x = (x * x) % mod)
        if (n & 1) res = (res * x) % mod;
    return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m; map<int, int> freq;
        for(int i = 0; i < n; i++){
            int x; cin >> x; freq[x]++;
        }

        ll res = 0; auto i = freq.begin();

        for(auto j = ++freq.begin(); i != freq.end(); ++j){
            auto k = j; k--;
            if(j != freq.end() && (j->first - k->first) == 1) continue;

            int cnt = 0; ll cur = 1; auto first = i;

            for(k = i; k != j; ++k) {
                cur = (cur * k->second) % mod;
                if(++cnt == m + 1){ 
                    cur = (cur * modInv(first->second)) % mod;
                    --cnt; ++first;
                }
                if(cnt == m) { res = (res + cur) % mod; }
            }
            i = j;
        }
        cout << res << '\n';
    }
}