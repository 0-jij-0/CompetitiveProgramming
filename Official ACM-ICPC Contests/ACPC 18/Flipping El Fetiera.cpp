#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

vector<double> binom(double p, int k) {
	vector<double> res(k + 1);
	res[0] = pow(1.0 - p, k);
	for (int i = 1; i <= k; i++) {
		double a = p * (k - i + 1);
		double b = (1 - p) * i;
		res[i] = (b == 0.0) ? 1.0 : a * res[i - 1] / b;
	}
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ifstream ifs("fetiera.in");
	int t; ifs >> t;
	while (t--) {
		int n, k; ifs >> n >> k;
		ll total = (n + 1)*n / 2; total *= total;
		double expected = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cur; ifs >> cur;
				ll in = (ll)(i + 1)*(n - i)*(j + 1)*(n - j);
				double p = (double)in / total;
				vector<double> bin = binom(p, k);
				for (int i = (cur == 0); i <= k; i += 2) { expected += bin[i]; }
			}
		}
		cout << fixed << setprecision(6) << expected << '\n';
	}
	cin.ignore(2); return 0;
}