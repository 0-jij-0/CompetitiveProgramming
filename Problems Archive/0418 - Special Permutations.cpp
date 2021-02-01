#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m; v.resize(m);
	for (auto &x : v) { cin >> x; }
	vector<long long> res(n + 2, 0);
	for (int i = 1; i < m; i++) {
		int a = v[i], b = v[i - 1];
		if (a > b) { swap(a, b); }
		if (a == b) { continue; }
		res[1] += b - a; res[a] -= b - a;
		res[a] += b - 1; res[a + 1] -= b - 1;
		res[a + 1] += b - a - 1; res[b] -= b - a - 1;
		res[b] += a; res[b + 1] -= a;
		res[b + 1] += b - a;
	}
	long long pref = 0;
	for (int i = 1; i <= n; i++) {
		pref += res[i]; cout << pref << ' ';
	}
	cout << endl; cin.ignore(2); return 0;
}