#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;

vector<pair<int, int>> v;
map<int, int> comp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) {
		cin >> x.first >> x.second;
		comp[x.first]; comp[x.second]; comp[x.second + 1];
	}

	int idx = 0; for (auto& x : comp) x.second = idx++;

	vector<ll> tv(comp.size() + 1);
	for (auto& x : v) {
		tv[comp[x.first]]++; 
		tv[comp[x.second] + 1]--;
	}
	partial_sum(tv.begin(), tv.end(), tv.begin());
	for (auto& x : tv) x = (x == 1);
	partial_sum(tv.begin(), tv.end(), tv.begin());
	
	int res = -1; for (int i = 0; i < n; i++) {
		int R = tv[comp[v[i].second]];
		int L = comp[v[i].first] ? tv[comp[v[i].first] - 1] : 0;
		if (R - L == 0) { res = i + 1; break; }
	}

	cout << res << '\n';
}