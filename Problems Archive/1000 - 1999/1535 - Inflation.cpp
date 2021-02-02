#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef double ld;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; v.resize(n);
    for (auto& x : v) { cin >> x; }
    sort(v.begin(), v.end());

    ld res = 1.0; bool ok = true;
    for (int i = 0; i < n; i++) {
        if (v[i] > i + 1) { ok = false; break; }
        res = min(res, (v[i] + 0.0) / (i + 1.0));
    }
    if (!ok) { cout << -1 << '\n'; }
    else { cout << fixed << setprecision(6) << res << '\n'; }
    cin.ignore(2); return 0;
}