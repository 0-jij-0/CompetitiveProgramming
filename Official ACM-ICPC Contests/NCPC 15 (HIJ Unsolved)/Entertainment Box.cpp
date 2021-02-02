#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<int, int>> v;
multiset<int> occ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x.first >> x.second; }
	sort(v.begin(), v.end()); int res = n;
	for (auto &x : v) {
		while (!occ.empty() && *occ.begin() <= x.first) { occ.erase(occ.begin()); }
		occ.insert(x.second); if ((int)occ.size() > k) { res--; occ.erase(occ.find(*occ.rbegin())); }
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}