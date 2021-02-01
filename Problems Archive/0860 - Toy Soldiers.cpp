#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> v;
vector<pair<int, int>> p;
map<int, int> c;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; c[x]++; }
	if (c[v[0]] == n) { cout << 0 << endl; return 0; }
	int m; cin >> m; p.resize(m);
	for (auto &x : p) { cin >> x.first >> x.second; }
	int i = 0, res = -1;
	for (i = 0; i < m; i++) {
		int k = p[i].first, x = p[i].second; k--;
		c[v[k]]--; v[k] = x; c[x]++;
		if (c[x] == n) { res = i + 1; break; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}