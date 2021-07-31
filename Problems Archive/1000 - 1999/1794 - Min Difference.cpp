#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	int n, m; cin >> n >> m;
	a.resize(n); b.resize(m);
	for (auto& x : a) { cin >> x; }
	for (auto& x : b) { cin >> x; }
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0, res = 1 << 30;
	while (i != n && j != m) {
		res = min(res, abs(a[i] - b[j]));
		(a[i] < b[j] ? i++ : j++);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}