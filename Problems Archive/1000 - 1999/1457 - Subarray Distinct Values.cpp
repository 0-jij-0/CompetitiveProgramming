#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<int> v; map<int, int> m;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }
	int r = 0; ll res = 0;
	for (int i = 0; i < n; i++) {
		while (r != n && m.size() < k) { m[v[r++]]++; }
		while (r != n && m.count(v[r])) { m[v[r++]]++; }
		res += r - i; m[v[i]]--; if (m[v[i]] == 0) { m.erase(v[i]); }
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}