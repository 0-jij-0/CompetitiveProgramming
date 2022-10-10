#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }
	for (int i = 0; i < n; i++) v.push_back(v[i]);

	vector<int> maxLen(n, 0); ll cur = 0;
	for (int i = 0, len = 1; i < n; ++i, --len) {
		while (len <= n && cur + v[i + len - 1] <= k)
			cur += v[i + len++ - 1];
		maxLen[i] = len - 1; cur -= v[i];
	}

	int i = min_element(maxLen.begin(), maxLen.end()) - maxLen.begin();

	int res = n;
	for (int j = i; j <= i + maxLen[i]; j++) {
		int x = j % n, ans = 0, cur = 0;
		while (cur < n) { ans++; cur += maxLen[x]; x = (x + maxLen[x]) % n; }
		res = min(res, ans);
	}

	cout << res << '\n';
}