#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n, u; cin >> n >> u; v.resize(u);
	for (auto &x : v) { cin >> x.first >> x.second; }
	if (u == 0) { cout << 1 << endl; return 0; }
	sort(v.begin(), v.end()); int res = 0, r = v[0].second;
	if (v.front().first != 1) { res = 1; }
	for (int i = 1; i < u; i++) {
		if (v[i].first > r + 1) { res = r + 1; break; }
		r = max(r, v[i].second);
	}
	cout << (res ? res : n) << endl;
	cin.ignore(2); return 0;
}