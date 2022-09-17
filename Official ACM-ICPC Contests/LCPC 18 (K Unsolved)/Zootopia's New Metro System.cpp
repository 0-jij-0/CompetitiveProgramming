#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

const ll lo = 0b1111, hi = 0x7FFFFFFFFFFFFFF0;
string s; vector<int> A;
vector<vector<ll>> DP;

int main() {
    freopen("metro.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        DP.clear(); DP.resize(16, vector<ll>(11, -INF));
        int n; cin >> n >> s; A.resize(n);
        for (auto& x : A) cin >> x;
        
        DP[A[0] & lo][s[0] - '0'] = -A[0] - (A[0] & hi);

        ll res = -INF; cout << "0 ";
        for (int i = 1; i < n; i++, res = -INF) {
            int digit = s[i] - '0', low = A[i] & lo, high = A[i] & hi;

            for (int d = 0; d < 10; d++) for (int m = 0; m < 16; m++)
                res = max(res, DP[m][d] + A[i] - ((abs(d - digit)) ^ (m + A[i])));

            DP[low][digit] = max(DP[low][digit], res - A[i] - high);
            cout << res << ' ';
        }

        cout << '\n';
    }
}