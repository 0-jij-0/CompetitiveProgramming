#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

void getDivisorsHelper(int i, int curr, vector<pair<int, int>> &pf, vector<int> &v) {
    if (i == (int) pf.size()) { v.push_back(curr); return; }
    getDivisorsHelper(i + 1, curr, pf, v);
    for (int j = 0; j < pf[i].second; j++)
        getDivisorsHelper(i + 1, curr *= pf[i].first, pf, v);
}

vector<int> getDivisors(int x) {
    vector<pair<int, int>> pf;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) { continue; }
        int e = 0; while (x % i == 0) { e++; x /= i; }
        pf.push_back({i, e});
    }
    if (x != 1) { pf.push_back({x, 1}); }
    vector<int> res; getDivisorsHelper(0, 1, pf, res);
    return move(res);
}

ll countScenarios(map<int, vector<int>> &divisors, vector<int> &v) {
    int n = (int) divisors.size();

    map<int, ll> dp;
    for (int i = 0; i < n; i++) {
        int cur = v[i];
        vector<int> &d = divisors[v[i]];
        if ((cur & (cur - 1)) == 0) { dp[cur] = 0; continue; }

        dp[cur] = 1; for (auto& x : d) {
            if (x == cur) { continue; }
            if ((x & (x - 1)) == 0) { continue; }
            dp[cur] += dp[cur / x];
        }
    }
    return dp.rbegin()->second;
}

int main() {
    freopen("fame.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        int x; cin >> x;
        if (x < 3) { cout << 0 << '\n'; continue; }
        map<int, vector<int>> divisors;
        vector<int> v = getDivisors(x);
        sort(v.begin(), v.end());

        for (int i = 0; i < (int) v.size(); i++)
            for (int j = 0; j <= i; j++)
                if (v[i] % v[j] == 0) divisors[v[i]].push_back(v[j]);

        cout << countScenarios(divisors, v) << '\n';
    }
}