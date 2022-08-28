#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		A.resize(n); for (auto& x : A) cin >> x;
		B.resize(n); for (auto& x : B) cin >> x;

		vector<int> mi(n), ma(n); int j = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
			mi[i] = B[idx] - A[i]; ma[i] = B[j] - A[i];
			if (idx == i) { j = i - 1; }
		}

		for (auto& x : mi) cout << x << ' '; cout << '\n';
		for (auto& x : ma) cout << x << ' '; cout << '\n';
	}
}