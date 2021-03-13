#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef double ld;
typedef long long ll;

vector<int> X, Y;

ld dist(ll x, ll y) {
	ld dx = x * x, dy = y * y;
	return sqrt(dx + dy);
}

ld solve() {
	int n = (int)X.size(); ld res = 0;
	for (int i = 0; i < n; i++)
		res += dist(X[i], Y[i]);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; X.clear(); Y.clear();
		for (int i = 0; i < (n << 1); i++) {
			int x, y; cin >> x >> y;
			if (x) X.push_back(x);
			if (y) Y.push_back(y);
		}
		auto comp = [&](const int& i, const int& j) {return abs(i) < abs(j); };
		sort(X.begin(), X.end(), comp); sort(Y.begin(), Y.end(), comp);
		cout << fixed << setprecision(10) << solve() << '\n';
	}
	cin.ignore(2); return 0;
}