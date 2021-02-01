#include <iostream>
#include <vector>
using namespace std;
const int INF = -1 + (1 << 30);

vector<int> v, t, res;

int main() {
	int n, m; cin >> n >> m; res.resize(m, 0);
	v.resize(n + m); t.resize(n + m);
	for (auto &x : v) { cin >> x; }
	for (auto &x : t) { cin >> x; }

	v.push_back(INF << 1); t.push_back(1);
	int i = 0, j = 1, k = 0, l = 0;
	while (t[i] != 1) { i++; j++; }
	while (t[l] != 1) { res[0]++; l++; }
	while (t[j] != 1) { j++; }
	while (j <= n + m) {
		l = i + 1; while (l != j) {
			int left = v[l] - v[i];
			int right = v[j] - v[l];
			res[k + (right < left)]++; l++;
		}
		i = j; j++; k++;
		while (j < n + m && t[j] != 1) { j++; }
	}
	for (auto &x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}