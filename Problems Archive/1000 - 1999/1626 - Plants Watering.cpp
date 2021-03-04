#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> h, g, first, last;

int main() {
	freopen("plants.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; h.resize(n); g.resize(n);
	first.resize(n); last.resize(n);
	for (auto& x : h) { cin >> x; }
	for (auto& x : g) { cin >> x; }

	first[0] = 0; last[0] = 1 << 30;

	for (int i = 1; i < n; i++) {
		int f, l; if (h[i] >= h[i - 1]) {
			f = 0; if (g[i] >= g[i - 1]) { l = 1 << 30; }
			else { l = (h[i] - h[i - 1]) / (g[i - 1] - g[i]); }
		}
		else {
			if (g[i] <= g[i - 1]) { f = 1; l = 0; }
			else {
				f = (h[i - 1] - h[i] + (g[i] - g[i - 1] - 1)) / (g[i] - g[i - 1]);
				l = 1 << 30;
			}
		}
		first[i] = f; last[i] = l;
	}

	int maxF = *max_element(first.begin(), first.end());
	int minL = *min_element(last.begin(), last.end());
	cout << (maxF > minL ? -1 : maxF) << '\n';

	cin.ignore(2); return 0;
}