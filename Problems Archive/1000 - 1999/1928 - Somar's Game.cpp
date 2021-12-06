#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> A;

int main() {
	freopen("arr.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		int x, y; cin >> x >> y; x--; y--;
		for (auto& z : A) { cin >> z; }

		ll res = 0; if (x < y) {
			for (int i = 0; i <= x; i++) { res += A[i]; }
			int l = x, r = y; while (l < r - 1) { r--; res += A[++l]; }
		}
		else {
			for (int i = x; i < n; i++) { res += A[i]; }
			int l = y, r = x; while (l < r - 1) { l++; res += A[--r]; }
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}