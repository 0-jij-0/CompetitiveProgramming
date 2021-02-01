#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[200006];
int dp2[200006];
vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		dp1[0] = 1 << 30; dp1[1] = v[0];
		dp2[0] = 0; dp2[1] = 1 << 30;
		for (int i = 2; i <= n; i++) {
			dp1[i] = min(dp2[i - 1] + v[i - 1], dp2[i - 2] + v[i - 1] + v[i - 2]);
			dp2[i] = min(dp1[i - 1], dp1[i - 2]);
		}
		cout << min(dp1[n], dp2[n]) << '\n';
	}
	cin.ignore(2); return 0;
}