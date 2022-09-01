#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double ld;

vector<pair<ll, ll>> X;
vector<ll> Y;

int main() {
	freopen("syria.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, M; cin >> N >> M; 
		X.resize(N); for (auto& x : X) cin >> x.first >> x.second;
		Y.resize(M); for (auto& y : Y) cin >> y;
		sort(X.begin(), X.end()); sort(Y.begin(), Y.end());

		ld res = 0.0; int i = 0, j = 0;
		while (N && X.back().first >= Y.back()) {
			ll req = X.back().first - Y.back() + X.back().second;
			res = max(res, req * req + 0.0); X.pop_back(); N--;
		}

		while (i < N && X[i].first <= Y[0]) {
			ll req = Y[0] - X[i].first + X[i].second;
			res = max(res, req * req + 0.0); i++;
		}

		--i; while (++i < N) {
			while (Y[j + 1] <= X[i].first) { j++; }
			ll& O = X[i].first, & R = X[i].second, & A = Y[j], & B = Y[j + 1];

			ld M = (A + B) / 2.0; if (abs(M - O) > R) {
				ll reqA = O - A + R, reqB = B - O + R;
				ll req = min(reqA, reqB);
				res = max(res, req * req + 0.0);
			}
			else {
				ld H = abs(M - O); H *= H;
				H = R * R - H; ld D = M - A;
				res = max(res, H + D * D);
			}
		}

		cout << fixed << setprecision(6) << sqrt(res) << '\n';
	}
}