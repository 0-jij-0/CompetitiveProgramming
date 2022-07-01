#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef double ld;
const ld EPS = 1e-10;

ld c, m, p, v, res;

void E(ld c, ld m, ld p, const ld& v, ld prob = 1.0, int len = 0) {
	res += p * prob * (len + 1);
	if (c < EPS && m < EPS) { return; }
	if (c < EPS) {
		ld M = (v - m > EPS ? -1.0 : m - v);
		ld P = p + min(m, v);
		return E(c, M, P, v, prob * m, len + 1);
	}
	if (m < EPS) {
		ld C = (v - c > EPS ? -1.0 : c - v);
		ld P = p + min(c, v);
		return E(C, m, P, v, prob * c, len + 1);
	}
	ld C, M, P;
	C = (v - c > EPS ? -1.0 : c - v);
	M = m + min(v, c) / 2.0;
	P = p + min(v, c) / 2.0;
	E(C, M, P, v, prob * c, len + 1);

	C = c + min(v, m) / 2.0;
	M = (v - m > EPS ? -1.0 : m - v);;
	P = p + min(v, m) / 2.0;
	E(C, M, P, v, prob * m, len + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> c >> m >> p >> v; res = 0.0; E(c, m, p, v);
		cout << fixed << setprecision(10) << res << '\n';
	}
}