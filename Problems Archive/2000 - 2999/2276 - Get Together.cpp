#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef double ld;
const ld INF = 1e20;

vector<int> X, V; int n;

bool check(ld t) {
	ld L = -INF, R = INF;
	for (int i = 0; i < n; i++) {
		ld curL = X[i] - t * V[i], curR = X[i] + t * V[i];
		L = max(L, curL); R = min(R, curR);
	}
	return L <= R;
}

ld minGatherTime() {
	ld L = 0.0, R = 1e10;
	for (int i = 0; i < 100; i++) {
		ld M = (L + R) / 2.0;
		check(M) ? R = M : L = M;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; X.resize(n); V.resize(n);
	for (int i = 0; i < n; i++) cin >> X[i] >> V[i];
	cout << fixed << setprecision(6) << minGatherTime() << '\n';
}

