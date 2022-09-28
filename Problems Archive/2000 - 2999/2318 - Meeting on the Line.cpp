#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double ld;
const ld INF = 1e10;

vector<int> x, t;

ld check(ld M) {
	ld L = -INF, R = INF; int n = (int)x.size();
	for (int i = 0; i < n; i++) {
		if (M < t[i]) return -1;
		ld curL = x[i] - (M - t[i]), curR = x[i] + M - t[i];
		L = max(L, curL); R = min(R, curR);
	}
	return L <= R ? L : -1;
}

ld minGatherTime() {
	ld L = 0.0, R = 1e9;
	for (int i = 0; i < 100; i++) {
		ld M = (L + R) / 2.0;
		check(M) != -1 ? R = M : L = M;
	}
	return check(R);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int n; cin >> n; x.resize(n); t.resize(n);
		for (auto& y : x) cin >> y;
		for (auto& y : t) cin >> y;
		
		cout << fixed << setprecision(6) <<  minGatherTime() << '\n';
	}
}