#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll k; cin >> n >> k; v.resize(n);
	for (int cur = n; cur; k -= --cur) {
		if (k + 1 >= cur) { v[n - cur] = cur; continue; }
		v[n - k - 1] = cur; int i = n - cur; cur = 1;
		for (int x = 1; i < n; i++)
			if (i != n - k - 1) { v[i] = x++; }
	}

	for (auto& x : v) cout << x << ' '; cout << '\n';
}