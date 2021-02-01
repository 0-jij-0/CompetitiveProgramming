#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> a;

int main() {
	int n; cin >> n; a.resize(n);
	for (auto &x : a) { cin >> x; }
	vector<int> v(21, 0);
	for (auto &x : a) {
		int i = 0;
		while (i < 21) if (x & (1 << i++)) { v[i - 1]++; }
	}
	ll res = 0; int num = n + 1;
	for (auto &x : v) if (x) num = min(num, x);
	while (*max_element(v.begin(), v.end())) {
		ll cur = 0;
		for (int i = 0; i < 21; i++) {
			if (v[i] == 0) { continue; }
			cur |= (1ll << i); v[i] -= num;
		}
		res += num * cur * cur;
		for (auto &x : v) if (x) num = min(num, x);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}
