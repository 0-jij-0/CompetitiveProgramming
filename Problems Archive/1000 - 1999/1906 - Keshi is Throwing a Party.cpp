#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

bool check(int k) {
	int cur = 0, n = (int)a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] + b[i] + 1 < k) { continue; }
		if (b[i] < cur) { continue; }
		if (a[i] < k - cur - 1) { continue; }
		cur++;
	}
	return cur >= k;
}

int findMaxPeople() {
	int l = 0, r = (int)a.size();
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		check(mid) ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

		cout << findMaxPeople() << '\n';
	}

	cin.ignore(2); return 0;
}