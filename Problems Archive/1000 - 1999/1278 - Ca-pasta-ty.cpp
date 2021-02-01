#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;
typedef long long ll;

vector<ll> S, X, Y;

void input(vector<ll> &v, const int &k, const int &n, ifstream &ifs) {
	for (int i = 0; i < k; i++) ifs >> v[i];
	ll a, b, c, d; ifs >> a >> b >> c >> d;
	for (int i = k; i < n; i++)
		v[i] = (((a * v[i - 2]) % d) + ((b * v[i - 1]) % d) + c) % d;
}

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; ifs >> n >> k; 
		S.clear(); X.clear(); Y.clear();
		S.resize(n); X.resize(n); Y.resize(n);
		input(S, k, n, ifs); input(X, k, n, ifs); input(Y, k, n, ifs);
		ll sS = accumulate(S.begin(), S.end(), 0ll);
		ll sX = accumulate(X.begin(), X.end(), 0ll);
		ll sY = accumulate(Y.begin(), Y.end(), 0ll);
		if (sS < sX || sS > (sX + sY)) { ofs << "Case #" << t << ": -1" << '\n'; continue; }

		ll less = 0, more = 0;
		for (int i = 0; i < n; i++)
			if (S[i] < X[i]) { less += X[i] - S[i]; }
			else if (S[i] > X[i] + Y[i]) { more += S[i] - X[i] - Y[i]; }

		ofs << "Case #" << t << ": " << max(less, more) << '\n';
	}
	return 0;
}