#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n); bool ok = true;
	set<int> s; int a = 1; while (a <= n) { s.insert(a++); }
	for (auto &x : v) { cin >> x; s.erase(x); }
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		if (v[i] > i + 2) { ok = false; break; }
		if (i == 0 && v[i]) { res[i] = 0; continue; }
		if (i == 0) { res[i] = *s.begin(); s.erase(s.begin()); continue; }
		if (v[i] != v[i - 1]) { res[i] = v[i - 1]; continue; }
		res[i] = *s.begin(); s.erase(s.begin());
	}
	if (!ok) { cout << -1 << endl; return 0; }
	for (auto &x : res) { cout << x << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}