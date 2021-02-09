#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v[10]; string s; int n, m;

bool check(string& r) {
	int cur = 0, i = 0;
	while (i < m) {
		auto it = lower_bound(v[r[i] - '0'].begin(), v[r[i] - '0'].end(), cur);
		if (it == v[r[i] - '0'].end()) { break; }
		i++; cur = *it + 1;
	}
	return i == m;
}

int main() {
	freopen("digits.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; n = (int)s.size();
	for (int i = 0; i < n; i++)
		v[s[i] - '0'].push_back(i);

	string r; for (int i = 0; i < 10; i++)
		if (!v[i].empty())r.push_back(i + '0');

	m = (int)r.size();
	string res = "9999999999";
	do {
		if (check(r)) { res = min(res, r); }
	} while (next_permutation(r.begin(), r.end()));

	cout << res << '\n';
	cin.ignore(2); return 0;
}