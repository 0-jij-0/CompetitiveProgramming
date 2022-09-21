#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> T, Z, Y; int n, m;

bool check(int M) {
	ll res = 0; 
	for (int i = 0; i < n; i++) {
		int cycle = T[i] * Z[i] + Y[i];
		int rem = min(M % cycle, T[i] * Z[i]);
		int cur = (M / cycle) * Z[i] + rem / T[i];
		res += cur;
	}
	return res >= m;
}

int minTime() {
	int l = 0, r = 1 << 30;
	while (l != r) {
		int mid = (l + r) >> 1;
		check(mid) ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n; 
	T.resize(n); Z.resize(n); Y.resize(n);
	for (int i = 0; i < n; i++) cin >> T[i] >> Z[i] >> Y[i];

	int res = minTime(); cout << res << '\n';
	for (int i = 0; i < n; i++) {
		int cycle = T[i] * Z[i] + Y[i];
		int rem = min(res % cycle, T[i] * Z[i]);
		int cur = (res / cycle) * Z[i] + rem / T[i];
		if (m >= cur) { cout << cur << ' '; m -= cur; }
		else { cout << m << ' '; m = 0; }
	}
}