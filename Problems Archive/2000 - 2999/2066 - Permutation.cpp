#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> res;
		vector<int> vis(n + 1, 0); int cur = 1;
		while (cur <= n) {
			if (vis[cur]) { cur++; continue; }
			int x = cur; while (x <= n) { 
				res.push_back(x); vis[x] = 1; x *= 2; 
			}
		}
		cout << 2 << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}