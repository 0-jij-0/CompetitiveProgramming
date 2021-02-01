#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

vector<ll> v; int n, k;

bool check(ll x) {
	ll sum = 0; int groups = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] > x) { return false; }
		if (sum + v[i] <= x) { sum += v[i]; continue; }
		sum = v[i]; groups++;
	}
	return groups <= k;
}

ll findMin() {
	ll l = 0, r = 1ll << 60;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

void printAns(ll x) {
	ll sum = 0; set<int> idx; 
	for (int i = n - 1; i >= 0; i--) {
		if (sum + v[i] <= x) { sum += v[i]; continue; }
		idx.insert(i); sum = v[i];
	}
	int j = 0; while (idx.size() != k - 1) { idx.insert(j++); }

	for (int i = 0; i < n - 1; i++) {
		cout << v[i] << (idx.count(i) ? " / " : " ");
	}
	cout << v.back() << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		printAns(findMin());
	}
	cin.ignore(2); return 0;
}