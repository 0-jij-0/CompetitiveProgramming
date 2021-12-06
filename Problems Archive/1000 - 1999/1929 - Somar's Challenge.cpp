#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int main() {
	freopen("ch.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n); int sum = 0;
		for (auto& x : a) { cin >> x; sum += x; }

		int maxL = -1, maxR = -1, maxS = 0, curL = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			cur += a[i]; if (cur < 0) { cur = 0; curL = i + 1; }
			if (cur > maxS) { maxL = curL; maxR = i; maxS = cur; }
		}
		cout << (maxS << 1) - sum << '\n';
	}

	cin.ignore(2); return 0;
}