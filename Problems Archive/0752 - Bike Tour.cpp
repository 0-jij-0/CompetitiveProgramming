#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; vector<int> v(n);
		for (auto &x : v) { cin >> x; }
		int res = 0;
		for (int i = 1; i < n - 1; i++)
			res += (v[i] > v[i - 1]) && (v[i] > v[i + 1]);

		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}