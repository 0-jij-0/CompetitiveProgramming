#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v(130, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	v[0] = v[1] = v[2] = v[3] = 1;
	for (int i = 4; i < 130; i++) {
		for (int j = 1; j * j <= i; j++)
			v[i] += v[i - j * j];
	}
	int t; cin >> t; while (t--) {
		ll n; cin >> n; auto it = lower_bound(v.begin(), v.end(), n);
		cout << it - v.begin() << '\n';
	}
	cin.ignore(2); return 0;
}