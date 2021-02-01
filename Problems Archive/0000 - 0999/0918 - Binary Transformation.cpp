#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
typedef long long ll;

vector<int> cost; string s, t; 
multiset<int> toZero, toOne, other;

ll computeAns(ll init) {
	ll ans = init * (toOne.size() + toZero.size());
	vector<ll> toZ; for (auto &x : toZero) { toZ.push_back(x); }
	vector<ll> toO; for (auto &x : toOne) { toO.push_back(x); }
	if (!toZ.empty()) { partial_sum(toZ.begin(), toZ.end(), toZ.begin()); }
	if (!toO.empty()) { partial_sum(toO.begin(), toO.end(), toO.begin()); }
	if (!toZ.empty()) { ans += accumulate(toZ.begin(), toZ.end() - 1, 0ll); }
	if (!toO.empty()) { ans += accumulate(toO.begin(), toO.end(), 0ll); }
	return ans;
}

int main() {
	int n; cin >> n; cost.resize(n);
	for (auto &x : cost) { cin >> x; }
	ll init = 0; cin >> s >> t;
	for (int i = 0; i < n; i++) {
		if (s[i] + t[i] == 2 * '0') { continue; }
		if (s[i] + t[i] == 2 * '1') { other.insert(cost[i]); init += cost[i]; continue; }
		(s[i] == '0' ? toOne : toZero).insert(cost[i]);
	}
	ll res = computeAns(init);
	while (!other.empty()) {
		toZero.insert(*other.rbegin()); toOne.insert(*other.rbegin());
		init -= *other.rbegin(); other.erase(other.find(*other.rbegin()));
		res = min(res, computeAns(init));
	}
	cout << res << endl; cin.ignore(2); return 0;
}