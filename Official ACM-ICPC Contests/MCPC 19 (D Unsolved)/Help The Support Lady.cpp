#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> v;

int main() {
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end());

		int res = 0; ll cur = 0;
		for (int j = 0; j < n; j++)
			if (cur <= v[j]) { res++; cur += v[j]; }

		cout << "Case #" << i + 1 << ": " << res << endl;
	}
	cin.ignore(2); return 0;
}