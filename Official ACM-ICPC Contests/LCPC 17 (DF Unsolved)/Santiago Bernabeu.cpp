#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	freopen("bernabeu.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, K; cin >> N >> K; v.resize(N);
		for (auto& x : v) cin >> x;
		sort(v.begin(), v.end());

		int res = 0;
		for (int i = 0, j = 0; i < N; i++) {
			while (j < N && v[j] - v[i] <= K) { j++; }
			res = max(res, j - i);
		}

		cout << res << '\n';
	}
}