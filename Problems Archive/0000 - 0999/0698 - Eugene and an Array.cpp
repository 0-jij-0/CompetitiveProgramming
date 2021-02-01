#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v, pref;
set<ll> cur;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	while (!v.empty() && v.back() == 0) { v.pop_back(); }
	reverse(v.begin(), v.end());
	while (!v.empty() && v.back() == 0) { v.pop_back(); }
	reverse(v.begin(), v.end());

	n = (int)v.size(); pref.resize(n);
	partial_sum(v.begin(), v.end(), pref.begin());
	pref.insert(pref.begin(), 0);
	long long res = 0; int i = 0, j = 0, lastj = -1;
	while (j != n + 1) {
		if (!cur.count(pref[j])) { cur.insert(pref[j]); j++; continue; }
		ll s = cur.size() - 1; res += (s*(s + 1) / 2);
		if (i <= lastj) { s = lastj - i; res -= (s*(s + 1)) / 2; }
		lastj = j - 1; while (cur.count(pref[j])) { cur.erase(pref[i]); i++; }
		cur.insert(pref[j]); j++;
	}
	ll s = cur.size() - 1; res += (s*(s + 1) / 2);
	if (i <= lastj) { s = lastj - i; res -= (s*(s + 1)) / 2; }
	cout << res << endl; cin.ignore(2); return 0;
}