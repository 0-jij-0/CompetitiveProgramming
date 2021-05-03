#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());

		int res = 0, prevMax = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0 && v[0] == 1) { continue; }
			if (i == 0) { res = prevMax = v[0] - 1; continue; }
			if (v[i] - v[i - 1] < 2) { continue; }
			int d = v[i] - v[i - 1] - 1;
			res = max({ res, d, prevMax + (d + 1) / 2 });
			prevMax = max(prevMax, (d + 1) / 2);
		}
		res = max(res, prevMax + k - v.back());
		double prob = (res + 0.0) / (k + 0.0);
		cout << fixed << setprecision(8);
		cout << "Case #" << t << ": " << prob << '\n';
	}
	cin.ignore(2); return 0;
}