#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> v;

int main() {
	int n, x; cin >> n >> x; v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first; v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if (v[i].first + v[j].first + v[k].first < x) { j++; continue; }
			if (v[i].first + v[j].first + v[k].first > x) { k--; continue; }
			cout << v[i].second << ' ' << v[j].second << ' ' << v[k].second << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}