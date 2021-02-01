#include <iostream>
#include <vector>
using namespace std;

vector<int> v, p;

int main() {
	int n, x; cin >> n >> x; v.resize(n); p.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i] >> p[i];

	int cur = 0, res = -1; x *= 100;
	for (int i = 0; i < n; i++) {
		cur += v[i] * p[i];
		if (cur > x) { res = i + 1; break; }
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}