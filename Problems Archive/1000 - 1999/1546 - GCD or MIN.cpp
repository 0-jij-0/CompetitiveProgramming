#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	set<int> ans; for(auto &x : v)
		for(int i = 1; i * i <= x; i++)
			if (x % i == 0) {
				if (i <= v[0]) ans.insert(i);
				if (x / i <= v[0]) ans.insert(x / i);
			}

	int res = 0; for (auto& x : ans) {
		int g = 0; for (auto& y : v)
			if (y % x == 0) g = gcd(y, g);
		res += g == x;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}