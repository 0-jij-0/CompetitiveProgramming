#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> v;

bool compare(const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
	return 2 * p1.first + p1.second < 2 * p2.first + p2.second;
}

int main() {
	int n; cin >> n; v.resize(n); ll A = 0;
	for (auto& x : v) { cin >> x.first >> x.second; A += x.first; }
	sort(v.rbegin(), v.rend(), compare);

	ll res = 0; int i = 0; for (; i < n; i++) {
		res += 2 * v[i].first + v[i].second;
		if (res > A) { break; }
	}
	cout << i + 1 << '\n';
	cin.ignore(2); return 0;
}