#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; S.resize(n);
		for (auto& x : S) cin >> x;
		sort(S.begin(), S.end());

		int res = 0; 
		for (auto& x : S) res += x > res;

		cout << "Case #" << t << ": " << res << '\n';
	}

	cin.ignore(2); return 0;
}