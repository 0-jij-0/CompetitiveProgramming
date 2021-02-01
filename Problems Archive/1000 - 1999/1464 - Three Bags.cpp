#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v[3]; ll s[3];

int main() {
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	v[0].resize(n1); v[1].resize(n2); v[2].resize(n3);
	for (int i = 0; i < 3; i++) {
		for (auto& x : v[i]) { cin >> x; }
		sort(v[i].begin(), v[i].end());
		s[i] = accumulate(v[i].begin(), v[i].end(), 0ll);
	}

	ll ans1 = s[0] + s[1] - s[2];
	ll ans2 = s[1] + s[2] - s[0];
	ll ans3 = s[0] + s[2] - s[1];
	ll res = max({ ans1, ans2, ans3 });


	for (int i = 0; i < 3; i++) {
		int j = (i + 1) % 3, k = (i + 2) % 3;
		ll sub = v[i][0] + min(v[j][0], v[k][0]);
		res = max(res, s[i] + s[j] + s[k] - 2 * sub);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}