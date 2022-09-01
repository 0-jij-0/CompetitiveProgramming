#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<pair<int, int>, ll> slopeFreq;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll choose2(ll N) { return (N * (N - 1)) >> 1; }
ll choose3(ll N) { return N * (N - 1) * (N - 2) / 6; }

int main() {
	freopen("tournament.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N; cin >> N; slopeFreq.clear();
		for (int i = 0; i < N; i++) {
			int xp, yp, xc, yc; cin >> xp >> yp >> xc >> yc;
			int dx = xp - xc, dy = yp - yc;
			int g = gcd(abs(dx), abs(dy)); dx /= g; dy /= g; 

			if (dx < 0 || (!dx && dy < 0)) { dx *= -1; dy *= -1; }
			slopeFreq[{dy, dx}]++;
		}

		ll total = choose3(N);
		ll parallel = 0; for (auto& x : slopeFreq)
			parallel += choose3(x.second) + choose2(x.second) * (N - x.second);

		cout << total - parallel << '\n';
	}
}