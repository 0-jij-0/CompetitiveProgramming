#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

vector<int> r, c;
vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	v.resize(n); r.resize(n); c.resize(m);
	for (auto &x : v) { cin >> x; }
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (v[i][j] == '*') { r[i]++; c[j]++; }

	ll res = 0; for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == '*') res += (r[i] - 1) * (c[j] - 1);

	cout << res << '\n'; cin.ignore(2); return 0;
}